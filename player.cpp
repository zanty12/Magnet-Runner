/*==============================================================================

   プレイヤー管理 [player.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "player.h"
#include "input.h"
#include "sprite.h"
#include "texture.h"
#include "bullet.h"
#include "calculations.h"
#include "mapmngr.h"
#include "main.h"
#include "map.h"
#include <cmath>


//*****************************************************************************
// マクロ定義
//*****************************************************************************

#define ANIME_PTN_YOKO 3
#define ANIME_PTN_TATE 1
#define ANIME_PTN_WAIT 5

#define ANIME_PTN (ANIME_PTN_YOKO * ANIME_PTN_TATE)
#define ANIME_PTN_U (1.0f / ANIME_PTN_YOKO)
#define ANIME_PTN_V (1.0f / ANIME_PTN_TATE)
#define RPS 3 //1秒間何発撃てる


//*****************************************************************************
// グローバル変数
//*****************************************************************************
Mapmngr* mapmngr = nullptr;
Map* g_Map = nullptr;

//=============================================================================
// 初期化処理
//=============================================================================
Player::Player() : GameObject(D3DXVECTOR2(960.0f, 540.0f)) {
	TexNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	Size_ = D3DXVECTOR2(96.0f, 96.0f);
	mapmngr = (Mapmngr*)GetMapMngrInstance();
	g_Map = mapmngr->GetMap();
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel) : GameObject(pos)
{
	vel = vel;
	TexNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	Size_ = D3DXVECTOR2(96.0f, 96.0f);
	mapmngr = (Mapmngr*)GetMapMngrInstance();
	g_Map = mapmngr->GetMap();
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot) : GameObject(pos, color)
{
	vel = vel;
	rot = rot;
	TexNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	Size_ = D3DXVECTOR2(96.0f, 96.0f);
	mapmngr = (Mapmngr*)GetMapMngrInstance();
	g_Map = mapmngr->GetMap();
}

//=============================================================================
// 終了処理
//=============================================================================
Player::~Player() = default;


//=============================================================================
// 更新処理
//=============================================================================
void Player::Update(void)
{
	static bool isAnim = false;
	Vel_.x = 0.0f;
	Vel_.y = 0.0f;
	//キーボード
	if (GetKeyboardPress(DIK_W))
	{
		Vel_.y = -5.0f;
		isAnim = true;
		V_ = 0.75f;

	}
	if (GetKeyboardPress(DIK_S))
	{
		Vel_.y = 5.0f;
		isAnim = true;
		V_ = 0.0f;

	}
	if (GetKeyboardPress(DIK_A))
	{
		Vel_.x = -5.0f;
		isAnim = true;
		V_ = 0.25f;

	}
	if (GetKeyboardPress(DIK_D))
	{
		Vel_.x = 5.0f;
		isAnim = true;
		V_ = 0.5f;

	}

	if ((Vel_.y != 0.0f && Vel_.x < 0.0f) || Vel_.x < 0.0f)
		Rot_ = atan(Vel_.y / Vel_.x) - D3DX_PI;
	else if (Vel_.x != 0.0f || Vel_.y != 0.0f)
		Rot_ = atan(Vel_.y / Vel_.x);

	Pos_.x += Vel_.x;
	Pos_.y += Vel_.y;

	//collision with cells around

	//center
	Cell* cell = g_Map->GetCell(Pos_);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.x = cell->GetPos().x - cell->GetSize().x / 2 - Size_.x / 2;
			Pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - Size_.y / 2;
		}

	}
	//left
	cell = g_Map->GetCell(D3DXVECTOR2(Pos_.x - Size_.x / 2, Pos_.y));
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.x = cell->GetPos().x + cell->GetSize().x / 2 + Size_.x / 2;
		}
	}

	//right
	cell = g_Map->GetCell(D3DXVECTOR2(Pos_.x + Size_.x, Pos_.y));
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.x = cell->GetPos().x - cell->GetSize().x / 2 - Size_.x / 2;
		}
	}

	//top
	cell = g_Map->GetCell(D3DXVECTOR2(Pos_.x, Pos_.y - Size_.y));
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.y = cell->GetPos().y + cell->GetSize().y / 2 + Size_.y / 2;
		}

	}

	//bottom
	cell = g_Map->GetCell(D3DXVECTOR2(Pos_.x, Pos_.y + Size_.y));
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - Size_.y / 2;
		}
	}


	//border
	if (Pos_.x < Size_.x / 2)
		Pos_.x = Size_.x / 2;
	if (Pos_.y < 0.0f - Size_.y / 2)
		Pos_.y = 0.0f - Size_.y / 2;
	//bullets

	static int round = 0;
	if (GetKeyboardPress(DIK_SPACE))
	{
		if (round >= 60 / RPS)
		{
			round = 0;
			CreateBullet(Pos_, D3DXVECTOR2(4.0f * cos(Rot_), 4.0f * sin(Rot_)), Rot_ + 0.5f * D3DX_PI);
		}
	}
	round++;

	//ゲームパッド
	if (IsButtonPressed(0, BUTTON_A) || GetKeyboardPress(DIK_TAB))
	{
		//座標のリセット
		Pos_.x = SCREEN_WIDTH / 2;
		Pos_.y = SCREEN_HEIGHT / 2;
	}

	if (isAnim == true) {
		AnimeSkipFrame_++;
		if (AnimeSkipFrame_ > ANIME_PTN_WAIT)
		{
			AnimeSkipFrame_ = 0;

			AnimePattern_++;
			if (AnimePattern_ >= ANIME_PTN)
			{
				AnimePattern_ = 0;
			}
		}
	}
	else {
		AnimePattern_ = 1;

	}
	isAnim = false;
	U_ = (AnimePattern_ % ANIME_PTN_YOKO) * ANIME_PTN_U;
	//	V_ = (AnimePattern_ / ANIME_PTN_YOKO) * ANIME_PTN_V;
}

//=============================================================================
// 描画処理
//=============================================================================
void Player::Draw(void)
{
	//プレイヤーの描画

	DrawSpriteColor(TexNo_,
		Pos_.x, Pos_.y,
		96.0f, 96.0f,
		U_, V_,//UV値の始点
		ANIME_PTN_U, 0.25f,
		Color_.r, Color_.g, Color_.b, Color_.a);
}


