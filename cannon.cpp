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
	if (isShooting_) {
		Shoot();
	}
	for (auto& bullet : bullets_) {
		bullet->Update();
	}
}

void Cannon::Shoot() {

}