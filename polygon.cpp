/*==============================================================================

   頂点管理 [polygon.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "polygon.h"
#include "input.h"
#include "sprite.h"
#include "texture.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define NUM_POLYGON 2	//表示するポリゴンの数

#define ANIME_PTN_YOKO 10
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
struct POLYGON {
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
	float			rot;
};

static POLYGON g_Polygon[NUM_POLYGON];

static int g_TexNo = 0;
static float g_U = 0.0f;
static float g_V = 0.0f;
static int g_AnimePattern = 0;
static int g_AnimeTatePattern = 0;
static int g_AnimeSkipFrame = 0;

static int g_Score = 12345;
static unsigned int g_Second = 0;
static unsigned int g_MiliSecond = 0;
static unsigned int g_StartTime = 0;

//=============================================================================
// 初期化処理
//=============================================================================
void InitPolygon(void)
{
	ID3D11Device* pDevice = GetDevice();

	//テクスチャの読み込み
	g_TexNo = LoadTexture((char*)"data/TEXTURE/number000.png");

	//初期化

	for (int i = 0; i < NUM_POLYGON; i++)
	{
		g_Polygon[i].pos.x = frand() * SCREEN_WIDTH;
		g_Polygon[i].pos.y = frand() * SCREEN_HEIGHT;

		g_Polygon[i].vel.x = 0.0f;
		g_Polygon[i].vel.y = 0.0f;

		g_Polygon[i].color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		g_Polygon[i].rot = frand() * (D3DX_PI * 2);
	}

	//ゲームの開始時刻を保存する
	g_StartTime = timeGetTime();
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitPolygon(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePolygon(void)
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
	g_V = (g_AnimePattern / ANIME_PTN_YOKO) * ANIME_PTN_V;

	//経過した秒数を更新する
	g_Second = (timeGetTime() - g_StartTime) / 1000;

	g_MiliSecond = ((timeGetTime() - g_StartTime) / 10) % 100;
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawPolygon(void)
{
	int score = g_Score;

	for (int i = 0; i < 5; i++)
	{
		//スコアの描画
		DrawSpriteColorRotate(g_TexNo,
			1500.0f - (70.0f * i), 70.0f,
			70.0f, 140.0f,
			ANIME_PTN_U * (score % 10), 0.0f,//UV値の始点
			ANIME_PTN_U, ANIME_PTN_V,
			g_Polygon[0].color.r, g_Polygon[0].color.g, g_Polygon[0].color.b, g_Polygon[0].color.a,
			0.0f);

		score = score / 10;
	}

	int second = g_Second;

	//時間表示
	for (int i = 0; i < 5; i++)
	{
		//スコアの描画
		DrawSpriteColorRotate(g_TexNo,
			500.0f - (70.0f * i), 70.0f,
			70.0f, 140.0f,
			ANIME_PTN_U * (second % 10), 0.0f,//UV値の始点
			ANIME_PTN_U, ANIME_PTN_V,
			g_Polygon[0].color.r, g_Polygon[0].color.g, g_Polygon[0].color.b, g_Polygon[0].color.a,
			0.0f);

		second = second / 10;
	}

	int milisecond = g_MiliSecond;

	//ミリ秒表示
	for (int i = 0; i < 2; i++)
	{
		//スコアの描画
		DrawSpriteColorRotate(g_TexNo,
			710.0f - (70.0f * i), 70.0f,
			70.0f, 140.0f,
			ANIME_PTN_U * (milisecond % 10), 0.0f,//UV値の始点
			ANIME_PTN_U, ANIME_PTN_V,
			g_Polygon[0].color.r, g_Polygon[0].color.g, g_Polygon[0].color.b, g_Polygon[0].color.a,
			0.0f);

		milisecond = milisecond / 10;
	}
}