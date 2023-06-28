#pragma once

#include "main.h"
#include "renderer.h"
#include "gameobject.h"

class Block : public GameObject{

public:
	Block();
	Block(D3DXVECTOR2 pos);
	Block(D3DXVECTOR2 pos, D3DXCOLOR color);
	~Block();

};

