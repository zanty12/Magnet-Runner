#pragma once
#include "cell.h"


typedef enum {
	BLOCK_NONE = 0,
	BLOCK_NORMAL,
	BLOCK_PLUS,
	BLOCK_MINUS,
};

class Map
{
private:
	int Width_ = 20;
	int Height_ = 20;
	Cell** Map_ = nullptr;

public:
	Map();
	Map(int width, int height);
	~Map();
	void PutCell(int x, int y, Cell* cell) { Map_[y * Width_ + x] = cell; }
	void PutCell(int x, int y, int type);
	Cell* GetCell(int x, int y);
	void Draw();
	int GetWidth() { return Width_; }
	int GetHeight() { return Height_; }
	void SetWidth(int width) { Width_ = width; }
	void SetHeight(int height) { Height_ = height; }

	Cell* GetCell(D3DXVECTOR2 pos) {
		int x = (int)(pos.x / 96.0f);
		int y = (int)(pos.y / 96.0f);
		return GetCell(x,y);
	}
	

};

