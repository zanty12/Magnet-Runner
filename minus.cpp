#include "minus.h"
#include "texture.h"

Minus::Minus() :Block(CELL_BLOCK_MINUS)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/minus.png");
	pole_ = POLE_MINUS;
}

Minus::Minus(D3DXVECTOR2 pos) : Block(pos, CELL_BLOCK_MINUS)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/minus.png");
	pole_ = POLE_MINUS;
}

void Minus::Update()
{
	//TODO minus update
}