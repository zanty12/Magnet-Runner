#pragma once
#include "gamemodules.h"
#include "cell.h"
class Savepoint :
    public Cell
{
public:
	Savepoint(D3DXVECTOR2 pos) :Cell(CELL_SAVEPOINT) {
		pos_ = pos;
	}
	~Savepoint() override = default;
	void Update() override {};
	void Draw() override{};
};

