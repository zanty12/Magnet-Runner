/*==============================================================================

   �G�l�~�[�Ǘ�[bullet.h]
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
// �}�N����`
//*****************************************************************************
#define NUM_BULLET 5

//*****************************************************************************
// �v���g�^�C�v�錾
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
