#include "plus.h"
#include "sprite.h"
#include "texture.h"

Plus::Plus() : Block()
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/plus.png");
	
}

Plus::Plus(D3DXVECTOR2 pos) : Block(pos)
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/plus.png");
	
}

Plus::Plus(D3DXVECTOR2 pos, D3DXCOLOR color) : Block(pos, color)
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/plus.png");
	
}

Plus::~Plus()
{
}

