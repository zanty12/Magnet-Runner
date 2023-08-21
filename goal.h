#pragma once
#include "gamemodules.h"
#include "cell.h"
#include "texture.h"
class Goal :
	public Cell
{
public:
	Goal(D3DXVECTOR2 pos) :Cell(CELL_GOAL) { pos_ = pos;
	texNo_ = LoadTexture((char*)"data/TEXTURE/goal.png");
	}
	~Goal() override = default;
	void Update() {};
};
