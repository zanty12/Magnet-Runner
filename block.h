#pragma once

#include "main.h"
#include "renderer.h"
#include "cell.h"



class Block : public Cell{

public:
	Block();
	Block(CELL_TYPE type);
	Block(D3DXVECTOR2 pos);
	Block(D3DXVECTOR2 pos, CELL_TYPE type);
	~Block() override = default;
	void Update()override;

};

