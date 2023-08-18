#include "cannon.h"
#include "texture.h"

Cannon::Cannon(D3DXVECTOR2 pos, CELL_TYPE type) : Cell(pos, type)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/cannon.png");
	switch (type) {
	case(CELL_CANNON_LEFT):
		dir_ = DIRECTION_LEFT;
		break;
	case(CELL_CANNON_RIGHT):
		dir_ = DIRECTION_RIGHT;
		break;
	case(CELL_CANNON_UP):
		dir_ = DIRECTION_UP;
		break;
	case(CELL_CANNON_DOWN):
		dir_ = DIRECTION_DOWN;
		break;
	}
}

Cannon ::~Cannon()
{
	for (auto& bullet : bullets_) {
		delete bullet;
	}
	bullets_.clear();
}

void Cannon::Update()
{
	if (isShooting_&& coolTime_ == 0) {
		Shoot();
		coolTime_ = 90;
	}

	for (int i = 0; i < bullets_.size(); i++) {
		bullets_[i]->Update();
		if (!bullets_[i]->GetIsActive()) {
			delete bullets_[i];
			bullets_.erase(bullets_.begin() + i);
		}
	}
	
	if(coolTime_ > 0)
		coolTime_--;
}

void Cannon::Draw() {
	if (camera_->InCamera(pos_)) {
		float DiffX = camera_->GetPos().x - SCREEN_WIDTH / 2;
		float DiffY = camera_->GetPos().y - SCREEN_HEIGHT / 2;
		if (DiffX < 0)
			DiffX = 0;
		if (DiffY < 0)
			DiffY = 0;
		DrawSpriteColor(texNo_,
			pos_.x - DiffX, pos_.y - DiffY,
			size_.x, size_.y,
			0.0f, 0.0f,//UV’l‚ÌŽn“_
			1.0f, 1.0,
			color_.r, color_.g, color_.b, color_.a);
	}
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}

void Cannon::Shoot() {
	switch (dir_) {
	case(DIRECTION_UP):
		bullets_.push_back(new Bullet(pos_, D3DXVECTOR2(0.0f, -4.0f), 0.0f, POLE_NONE,camera_->GetPlayer()));
		break;
	case(DIRECTION_DOWN):
		bullets_.push_back(new Bullet(pos_, D3DXVECTOR2(0.0f, 4.0f), D3DX_PI, POLE_NONE, camera_->GetPlayer()));
		break;
	case(DIRECTION_LEFT):
		bullets_.push_back(new Bullet(pos_, D3DXVECTOR2(-4.0f, 0.0f), D3DX_PI * 1.5f, POLE_NONE, camera_->GetPlayer()));
		break;
	case(DIRECTION_RIGHT):
		bullets_.push_back(new Bullet(pos_, D3DXVECTOR2(4.0f, 0.0f), D3DX_PI * 0.5f, POLE_NONE, camera_->GetPlayer()));
		break;
	}
}
