#pragma once
#include "block.h"
class Minus :
	public Block
{
public:
	Minus();
	Minus(D3DXVECTOR2 pos);
	~Minus() override = default;
	void Update();
};
