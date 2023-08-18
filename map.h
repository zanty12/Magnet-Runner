#pragma once
#include "cell.h"

class Map
{
private:
	int width_ = 20;
	int height_ = 20;
	Cell** map_ = nullptr;

public:
	Map();
	Map(int width, int height);
	~Map();
	void PutCell(int x, int y, Cell* cell) { map_[y * width_ + x] = cell; }
	void PutCell(int x, int y, int type);
	Cell* GetCell(int x, int y);
	void Update();
	void Draw();
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }
	void SetWidth(int width) { width_ = width; }
	void SetHeight(int height) { height_ = height; }

	Cell* GetCell(D3DXVECTOR2 pos) {
		int x = (int)(pos.x / 96.0f);
		int y = (int)(pos.y / 96.0f);
		return GetCell(x, y);
	}
};
