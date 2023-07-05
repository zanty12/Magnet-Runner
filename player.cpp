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
Player::Player() : GameObject(D3DXVECTOR2(960.0f, 936.0f)) {
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
	if (Vel_.y < 5.0f) {
		Vel_.y += 5.0f;
	}
	if(Vel_.y >= 5.0f)
		Vel_.y = 5.0f;
	//キーボード
	if (GetKeyboardPress(DIK_SPACE))
	{
		Vel_.y = -15.0f;
		isAnim = true;
		V_ = 0.75f;

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

	//bottom
	int xIndex = std::floor(Pos_.x / Size_.x);
	int yIndex = std::floor(Pos_.y / Size_.y);

	Cell *cell = g_Map->GetCell(xIndex, yIndex + 1);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - Size_.y / 2;
		}
	}

	//top
	cell = g_Map->GetCell(xIndex, yIndex - 1);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.y = cell->GetPos().y + cell->GetSize().y / 2 + Size_.y / 2;
		}

	}

	xIndex = std::ceil(Pos_.x / Size_.x);
	yIndex = std::ceil(Pos_.y / Size_.y);
	
	//left
	cell = g_Map->GetCell(xIndex - 1, yIndex);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.x = cell->GetPos().x + cell->GetSize().x / 2 + Size_.x / 2;
		}
	}


	xIndex = std::floor(Pos_.x / Size_.x);
	yIndex = std::floor(Pos_.y / Size_.y);

	//right
	cell = g_Map->GetCell(xIndex + 1, yIndex);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.x = cell->GetPos().x - cell->GetSize().x / 2 - Size_.x / 2;
		}
	}

	

	
	//center
	/*cell = g_Map->GetCell(xIndex, yIndex);
	if (cell != nullptr)
	{
		if (CheckHitBB(Pos_.x, Pos_.y, Size_.x, Size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			Pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - Size_.y / 2;
		}

	}*/

	//border
	if (Pos_.x < Size_.x / 2)
		Pos_.x = Size_.x / 2;
	if (Pos_.y < 0.0f - Size_.y / 2)
		Pos_.y = 0.0f - Size_.y / 2;
	

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


