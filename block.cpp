#include "block.h"
#include "sprite.h"
#include "texture.h"
#include "main.h"

Block::Block() :Cell()
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::Block(D3DXVECTOR2 pos) : Cell(pos)
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::Block(D3DXVECTOR2 pos, D3DXCOLOR color)
	:Cell(pos,color){
	TexNo_ = LoadTexture((char*)"data/TEXTURE/block.png");
}

Block::~Block()
{
}

void Block::Update()
{
	
}

