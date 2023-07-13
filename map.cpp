#include "map.h"
#include "block.h"
#include "plus.h"
#include "minus.h"

Map::Map()
{
	map_ = new Cell * [width_ * height_];
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			map_[i * width_ + j] = nullptr;
		}
	}
}

Map::Map(int width, int height) :width_(width), height_(height)
{
	map_ = new Cell * [width_ * height_];
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			map_[i * width_ + i] = nullptr;
		}
	}
}

Map::~Map()
{
	for (int i = 0; i < width_ * height_; i++)
		if (map_[i] != nullptr)
			delete map_[i];
}

Cell* Map::GetCell(int x, int y) {
	if (x < 0 || x >= width_ || y < 0 || y >= height_)
		return nullptr;
	return map_[y * width_ + x];
}

void Map::PutCell(int x, int y, int type)
{
	switch (type) {
	case(CELL_BLOCK_NORMAL):
		map_[y * width_ + x] = new Block(D3DXVECTOR2(x * 96.0f + CELL_SIZE / 2, y * 96.0f + CELL_SIZE / 2));
		break;
	case(CELL_BLOCK_PLUS):
		map_[y * width_ + x] = new Plus(D3DXVECTOR2(x * 96.0f + CELL_SIZE / 2, y * 96.0f + CELL_SIZE / 2));
		break;
	case(CELL_BLOCK_MINUS):
		map_[y * width_ + x] = new Minus(D3DXVECTOR2(x * 96.0f + CELL_SIZE / 2, y * 96.0f + CELL_SIZE / 2));
		break;
	default:
		map_[y * width_ + x] = nullptr;
		break;
	}
}

void Map::Draw()
{
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (map_[i * width_ + j] != nullptr) {
				map_[i * width_ + j]->Draw();
			}
		}
	}
}