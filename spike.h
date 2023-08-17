#pragma once
#include "gamemodules.h"
#include "cell.h"
#include "player.h"

class Spike :
    public Cell
{
private:
	DIRECTION dir_ = DIRECTION_UP;

    public:
	Spike(D3DXVECTOR2 pos, CELL_TYPE type);
	~Spike() = default;
	void Update() override;
	void Draw() override;
	

};

