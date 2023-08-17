#include "spike.h"
#include "texture.h"
#include "sprite.h"

Spike::Spike(D3DXVECTOR2 pos, CELL_TYPE type) : Cell(pos, type)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/spike.png");
	switch (type) {
	case(CELL_SPIKE_LEFT):
		dir_ = DIRECTION_LEFT;
		break;
	case(CELL_SPIKE_RIGHT):
		dir_ = DIRECTION_RIGHT;
		break;
	case(CELL_SPIKE_UP):
		dir_ = DIRECTION_UP;
		break;
	case(CELL_SPIKE_DOWN):
		dir_ = DIRECTION_DOWN;
		break;
	}
}

void Spike::Update() {

}

void Spike::Draw() {

	if (camera_->InCamera(pos_)) {
		float DiffX = camera_->GetPos().x - SCREEN_WIDTH / 2;
		float DiffY = camera_->GetPos().y - SCREEN_HEIGHT / 2;
		if (DiffX < 0)
			DiffX = 0;
		if (DiffY < 0)
			DiffY = 0;
		DrawSpriteColorRotate(texNo_,
			pos_.x - DiffX, pos_.y - DiffY,
			size_.x, size_.y,
			0.0f, 0.0f,//UV’l‚ÌŽn“_
			1.0f, 1.0,
			color_.r, color_.g, color_.b, color_.a,dir_ * D3DX_PI / 2);
	}
}
	
