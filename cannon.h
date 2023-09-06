#pragma once

#include "gamemodules.h"
#include "cell.h"
#include <vector>
#include "bullet.h"
#include "player.h"


class Cannon : public Cell {
private :
	std::vector<Bullet*> bullets_;
	bool isShooting_ = true;
	int coolTime_ = 30;
	DIRECTION dir_ = DIRECTION_LEFT;
	float rot_;
	public:
		Cannon (D3DXVECTOR2 pos, CELL_TYPE type);
		~Cannon() override;
		void Update() override;
		void Draw() override;
private:
		void Shoot();
};