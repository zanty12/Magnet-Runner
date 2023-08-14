#pragma once

#include "gamemodules.h"
#include "cell.h"
#include <vector>
#include "bullet.h"
#include "player.h"


class Cannon : public Cell {
private :
	std::vector<Bullet*> bullets_;
	bool isShooting_ = false;
	DIRECTION dir_ = DIRECTION_LEFT;
	public:
		Cannon (D3DXVECTOR2 pos, CELL_TYPE type);
		~Cannon() override;
		void Update() override;
private:
		void Shoot();
};