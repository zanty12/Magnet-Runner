#include "plus.h"
#include "texture.h"

Plus::Plus() : Block(CELL_BLOCK_PLUS)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/plus.png");
	pole_ = POLE_PLUS;
	
}

Plus::Plus(D3DXVECTOR2 pos) : Block(pos, CELL_BLOCK_PLUS)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/plus.png");
	pole_ = POLE_PLUS;
}

void Plus::Update()
{
	//TODO: Update
}

