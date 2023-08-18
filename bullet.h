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

class Bullet : public GameObject {

private:
	bool isActive_;
	D3DXVECTOR2 vel_;
	float rot_ = 0.0f;
	Player* player_ = nullptr;
public:
	Bullet(D3DXVECTOR2 pos,D3DXVECTOR2 vel, float rot, POLE pole,Player*player);
	~Bullet() = default;
	void Update();
	void Draw();
	bool GetIsActive() { return isActive_; }

};

