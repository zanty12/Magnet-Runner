#include "cannon.h"

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
