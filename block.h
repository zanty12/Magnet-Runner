#pragma once

#include "main.h"
#include "renderer.h"
#include "cell.h"

class Block : public Cell{

public:
	Block();
	Block(D3DXVECTOR2 pos);
	Block(D3DXVECTOR2 pos, D3DXCOLOR color);
	~Block();
	void Update()override;

};

