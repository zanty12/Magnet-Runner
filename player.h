/*==============================================================================

   プレイヤー管理[player.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#include "main.h"
#include "renderer.h"
#include "gameobject.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

class Player : public GameObject {
private:
	D3DXVECTOR2		Vel_ = D3DXVECTOR2(0.0f, 0.0f);	//速度ベクトル
	float			Rot_ = 0;
	int AnimePattern_ = 0;
	int AnimeSkipFrame_ = 0;
public:
	Player();
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel);
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot);
	~Player();
	void Update(void) override;
	void Draw(void) override;
	D3DXVECTOR2 GetVel() { return Vel_; }
	float GetRotation() { return Rot_; }
	void SetVel(D3DXVECTOR2 vel) { Vel_ = vel; }
	void SetRotation(float rot) { Rot_ = rot; }

};


