#pragma once
#include "block.h"
class Minus :
    public Block
{
    public:
	Minus();
	Minus(D3DXVECTOR2 pos);
	Minus(D3DXVECTOR2 pos, D3DXCOLOR color);
	~Minus();
	void Update();
};

