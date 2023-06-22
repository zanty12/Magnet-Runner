/*==============================================================================

   エネミー管理 [bullet.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "bullet.h"
#include "sprite.h"
#include "texture.h"
#include <vector>


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
struct BULLET_T{
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
	float			rot;
	bool destroyed;
};

static std::vector<BULLET_T> g_Bullet;

static int g_TexNo = 0;
static float g_U = 0.0f;
static float g_V = 0.0f;
static int g_AnimePattern = 0;
static int g_AnimeSkipFrame = 0;


//=============================================================================
// 初期化処理
//=============================================================================
void InitBullet(void)
{
	//テクスチャの読み込み
	g_TexNo = LoadTexture((char*)"data/TEXTURE/bullet00.png");

	//初期化
	
	
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitBullet(void)
{
	g_Bullet.clear();
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateBullet(void)
{
	for (int i = 0; i < GetBulletNum(); i++) {
		if (!g_Bullet[i].destroyed) {
			g_Bullet[i].pos += g_Bullet[i].vel;
		}
		if (g_Bullet[i].pos.x > 1920 || g_Bullet[i].pos.x < 0 || g_Bullet[i].pos.y > 1080 || g_Bullet[i].pos.y < 0)
			DestroyBullet(i);
	}
	
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
void DrawBullet(void)
{
	//エネミーの描画
	for (BULLET_T& bullet : g_Bullet) {
		if (!bullet.destroyed) {
			DrawSpriteColorRotate(g_TexNo,
				bullet.pos.x, bullet.pos.y,
				48.0f, 48.0f,
				g_U, g_V,//UV値の始点
				ANIME_PTN_U, 1.0f,
				bullet.color.r, bullet.color.g, bullet.color.b, bullet.color.a,
				bullet.rot);
		}	
	}
}


D3DXVECTOR2 GetBulletPos(int nIdx) {
	return g_Bullet[nIdx].pos;
}

int GetBulletNum() {
	return g_Bullet.size();
}

bool GetBulletState(int nIdx) {
	return g_Bullet[nIdx].destroyed;
}

void CreateBullet(D3DXVECTOR2 pos, D3DXVECTOR2 vel,float rot) {
	BULLET_T bullet = {pos, vel, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), rot, false };
	
	g_Bullet.push_back(bullet);
}

void DestroyBullet(int idx) {
	g_Bullet[idx].destroyed = true;
	g_Bullet.erase(g_Bullet.begin() + idx);
}
