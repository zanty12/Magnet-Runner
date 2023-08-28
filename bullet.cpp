/*==============================================================================

   エネミー管理 [bullet.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "bullet.h"
#include "texture.h"
#include "sprite.h"
#include "calculations.h"
#include "player.h"
#include "camera.h"

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 vel, float rot, POLE pole, Player* player, Camera* camera) :GameObject(pos, D3DXVECTOR2(96.0f, 96.0f))
{
	vel_ = vel;
	rot_ = rot;
	pole_ = pole;
	player_ = player;
	camera_ = camera;
	isActive_ = true;
	texNo_ = LoadTexture((char*)"data/TEXTURE/bullet00.png");
}

void Bullet::Update() {
	if (isActive_) {
		pos_ += vel_;
	}
	if (pos_.x < 0 || pos_.y < 0) {
		isActive_ = false;
	}
	if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, player_->GetPos().x, player_->GetPos().y, player_->GetSize().x, player_->GetSize().y)) {
		player_->DecreaseLife();
		player_->Invincible();
		isActive_ = false;
	}
}

void Bullet::Draw() {
	float DiffX = camera_->GetPos().x - SCREEN_WIDTH / 2;
	float DiffY = camera_->GetPos().y - SCREEN_HEIGHT / 2;
	if (DiffX < 0)
		DiffX = 0;
	if (DiffY < 0)
		DiffY = 0;
	DrawSpriteColorRotate(texNo_,
		pos_.x - DiffX, pos_.y - DiffY,
		size_.x, size_.y,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0,
		color_.r, color_.g, color_.b, color_.a,rot_);
}