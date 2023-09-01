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
#include "gamemodules.h"

typedef enum {
	DIRECTION_UP = 0,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_CENTER,
	DIRECTION_MAX
}DIRECTION;

typedef enum {
	GRAV_NORMAL = 0,
	GRAV_HALF
}GRAV_STATE;

class Player : public GameObject {
private:
	D3DXVECTOR2		vel_ = D3DXVECTOR2(0.0f, 0.0f);	//速度ベクトル
	float			rot_ = 0.0f;
	int animePattern_ = 0;
	int animeSkipFrame_ = 0;
	bool isGravity_ = true;
	GRAV_STATE gravState_ = GRAV_NORMAL;
	bool jumped_ = false;
	bool grounded_ = false;
	Cell* interactCell_[5] = { nullptr,nullptr,nullptr,nullptr,nullptr };
	Cell* oldInteractCell_[5] = { nullptr,nullptr,nullptr,nullptr,nullptr };
	DIRECTION direction_ = DIRECTION_CENTER;
	int life_ = 3;
	bool isClear_ = false;
	bool isInvincible_ = false;
	int invincibleFrame_ = 180;
	D3DXVECTOR2 startpoint_ = D3DXVECTOR2(0.0f,0.0f);
	Cell* savepoint_ = nullptr;

	Mapmngr* mapmngr_ = nullptr;
	Map* map_ = nullptr;
	Camera* camera_ = nullptr;

	int moveTex_ = 0;
	bool isMove_ = false;
	bool animReverse_ = false;

public:
	Player();
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel);
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot);
	~Player();
	void Init(Mapmngr* MapmngrInstance, Camera* CameraInstance,D3DXVECTOR2 Start);
	void Update(void) override;
	void Draw(void) override;
	D3DXVECTOR2 GetVel() { return vel_; }
	float GetRotation() { return rot_; }
	void SetVel(D3DXVECTOR2 vel) { vel_ = vel; }
	void SetRotation(float rot) { rot_ = rot; }
	int GetLife() { return life_; }
	void DecreaseLife() { if (life_ >0)life_--; }
	void AddLife() { if(life_ < 3)life_++; }
	bool GetIsClear() {return isClear_; }
	void Invincible() { isInvincible_ = true; }

private:
	void CellInteract(Cell* cell, DIRECTION direction);
	void BlockInteract(Cell* cell, DIRECTION direction);
	void PoleBlockInteract(Cell* cell, DIRECTION direction);
	void SpikeInteract(Cell* cell, DIRECTION direction);
};