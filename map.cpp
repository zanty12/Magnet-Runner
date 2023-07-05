#include "map.h"
#include "block.h"
#include "plus.h"
#include "minus.h"


Map::Map()
{
	Map_ = new Cell * [Width_ * Height_];
	for (int i = 0; i < Height_; i++) {
		for (int j = 0; j < Width_; j++) {
			Map_[i * Width_ + j] = nullptr;
		}
	}
}

Map::Map(int width, int height) :Width_(width), Height_(height)
{
	Map_ = new Cell * [Width_ * Height_];
	for (int i = 0; i < Height_; i++) {
		for (int j = 0; j < Width_; j++) {
			Map_[i * Width_ + i] = nullptr;
		}
	}

}


Map::~Map()
{
	for(int i = 0; i < Width_*Height_; i++)
		if(Map_[i] != nullptr)
			delete Map_[i];
	
}

Cell* Map::GetCell(int x, int y) {
	if(x < 0 || x >= Width_ || y < 0 || y >= Height_)
		return nullptr;
	return Map_[y * Width_ + x];
}

void Map::PutCell(int x, int y, int type)
{
	switch (type) {
	case(BLOCK_NORMAL):
		Map_[y * Width_ + x] = new Block(D3DXVECTOR2(x * 96.0f, y * 96.0f));
		break;
	case(BLOCK_PLUS):
		Map_[y * Width_ + x] = new Plus(D3DXVECTOR2(x * 96.0f, y * 96.0f));
		break;
	case(BLOCK_MINUS):
		Map_[y * Width_ + x] = new Minus(D3DXVECTOR2(x * 96.0f, y * 96.0f));
		break;
	default:
		Map_[y * Width_ + x] = nullptr;
		break;
	}
}
	

void Map::Draw()
{
	for (int i = 0; i < Height_; i++) {
		for (int j = 0; j < Width_; j++) {
			if (Map_[i * Width_ + j] != nullptr) {
				Map_[i * Width_ + j]->Draw();
			}
		}
	}

}
