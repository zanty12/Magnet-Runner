#include "block.h"
#include "sprite.h"
#include "texture.h"
#include "main.h"

Block::Block() :Cell(CELL_BLOCK_NORMAL)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::Block(CELL_TYPE type) :Cell(type)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::Block(D3DXVECTOR2 pos) : Cell(pos, CELL_BLOCK_NORMAL)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::Block(D3DXVECTOR2 pos, CELL_TYPE type) :Cell(pos, type)
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

void Block::Update()
{
}