#include "minus.h"
#include "texture.h"

Minus::Minus() :Block()
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/minus.png");

}

Minus::Minus(D3DXVECTOR2 pos) : Block(pos)
{
	TexNo_ = LoadTexture((char*)"data/TEXTURE/minus.png");
}

Minus::Minus(D3DXVECTOR2 pos, D3DXCOLOR color)
	:Block(pos, color) {
	TexNo_ = LoadTexture((char*)"data/TEXTURE/minus.png");
}

Minus::~Minus()
{
}

void Minus::Update()
{
	//TODO minus update
}
