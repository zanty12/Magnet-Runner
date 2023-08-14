/*==============================================================================

   エネミー管理[bullet.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once

#include "main.h"
#include "renderer.h"
#include "gamemodules.h"
#include "gameobject.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define NUM_BULLET 5

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

class Bullet : public GameObject {

};
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
D3DXVECTOR2 GetBulletPos(int nIdx);
int GetBulletNum();
void DestroyBullet(int nIdx);
bool GetBulletState(int nIdx);
void CreateBullet(D3DXVECTOR2 pos, D3DXVECTOR2 vel, float rot);
