/*==============================================================================

   エネミー管理 [enemy.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "enemy.h"
#include "sprite.h"
#include "texture.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************

#define ANIME_PTN_YOKO 1
#define ANIME_PTN_TATE 1
#define ANIME_PTN_WAIT 5


#define ANIME_PTN (ANIME_PTN_YOKO * ANIME_PTN_TATE)
#define ANIME_PTN_U (1.0f / ANIME_PTN_YOKO)
#define ANIME_PTN_V (1.0f / ANIME_PTN_TATE)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
struct ENEMY_T{
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
	float			rot;
	bool destroyed;
};

static ENEMY_T g_Enemy[NUM_ENEMY];

static int g_TexNo = 0;
static float g_U = 0.0f;
static float g_V = 0.0f;
static int g_AnimePattern = 0;
static int g_AnimeSkipFrame = 0;


//=============================================================================
// 初期化処理
//=============================================================================
void InitEnemy(void)
{
	//テクスチャの読み込み
	g_TexNo = LoadTexture((char*)"data/TEXTURE/enemy00.png");

	//初期化
	for (int i = 0; i < NUM_ENEMY; i++) {
		g_Enemy[i].pos.x = 560 + 200 * i;
		g_Enemy[i].pos.y = 200;
		g_Enemy[i].vel.x = 0.0f;
		g_Enemy[i].vel.y = 0.0f;
		g_Enemy[i].color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		g_Enemy[i].rot = 0.0f;
	}
	
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitEnemy(void)
{

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateEnemy(void)
{


	g_AnimeSkipFrame++;
	if (g_AnimeSkipFrame > ANIME_PTN_WAIT)
	{
		g_AnimeSkipFrame = 0;

		g_AnimePattern++;
		if (g_AnimePattern >= ANIME_PTN)
		{
			g_AnimePattern = 0;
		}
	}
	g_U = (g_AnimePattern % ANIME_PTN_YOKO) * ANIME_PTN_U;
//	g_V = (g_AnimePattern / ANIME_PTN_YOKO) * ANIME_PTN_V;
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawEnemy(void)
{
	//エネミーの描画
	for (int i = 0; i < NUM_ENEMY; i++) {
		if (!g_Enemy[i].destroyed) {
			DrawSpriteColorRotate(g_TexNo,
				g_Enemy[i].pos.x, g_Enemy[i].pos.y,
				96.0f, 96.0f,
				g_U, g_V,//UV値の始点
				ANIME_PTN_U, 1.0f,
				g_Enemy[i].color.r, g_Enemy[i].color.g, g_Enemy[i].color.b, g_Enemy[i].color.a,
				g_Enemy[i].rot);
		}	
	}
}


D3DXVECTOR2 GetEnemyPos(int nIdx) {
	return g_Enemy[nIdx].pos;
}

void DestroyEnemy(int nIdx) {
	g_Enemy[nIdx].destroyed = true;
}

bool GetEnemyState(int nIdx) {
	return g_Enemy[nIdx].destroyed;
}

