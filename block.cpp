#include "block.h"
#include "sprite.h"
#include "texture.h"

Block::Block() :GameObject()
{
	Size_ = D3DXVECTOR2(96.0f, 96.0f);
}

Block::Block(D3DXVECTOR2 pos) : GameObject(pos, D3DXVECTOR2(96.0f, 96.0f))
{

}

Block::Block(D3DXVECTOR2 pos, D3DXCOLOR color)
	:GameObject(pos, D3DXVECTOR2(96.0f, 96.0f),color){
}

Block::~Block()
{
}


