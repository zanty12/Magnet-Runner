#pragma once
#include "block.h"
class Plus :
	public Block
{
public:
	Plus();
	Plus(D3DXVECTOR2 pos);
	Plus(D3DXVECTOR2 pos, D3DXCOLOR color);
	~Plus();
	void Update() {}

};

