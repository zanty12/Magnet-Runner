#include "plus.h"
#include "sprite.h"
#include "texture.h"

Plus::Plus() : Block()
{
	SetTexture(LoadTexture((char*)"data/TEXTURE/plus.png"));
	
}

Plus::Plus(D3DXVECTOR2 pos) : Block(pos)
{
	SetTexture(LoadTexture((char*)"data/TEXTURE/plus.png"));
	
}

Plus::Plus(D3DXVECTOR2 pos, D3DXCOLOR color) : Block(pos, color)
{
	SetTexture(LoadTexture((char*)"data/TEXTURE/plus.png"));
	
}

Plus::~Plus()
{
}

