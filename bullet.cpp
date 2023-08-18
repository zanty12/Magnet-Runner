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

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 vel, float rot, POLE pole, Player* player) :GameObject(pos, D3DXVECTOR2(96.0f,96.0f))
{
	vel_= vel;
	rot_ = rot;
	pole_ = pole;
	player_ = player;
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
	DrawSpriteColorRotate(texNo_,
		pos_.x, pos_.y,
		size_.x / 2, size_.y / 2,
		u_, v_,//UV値の始点
		1.0f, 1.0f,
		color_.r, color_.g, color_.b, color_.a,
		rot_);
}






