#pragma once
#include "sprite.h"
#include "main.h"
#include "gameobject.h"

#define CELL_SIZE 96.0f

typedef enum {
	CELL_NONE = 0,
	CELL_BLOCK_NORMAL,
	CELL_BLOCK_PLUS,
	CELL_BLOCK_MINUS,
	CELL_CANNON_UP,
	CELL_CANNON_DOWN,
	CELL_CANNON_LEFT,
	CELL_CANNON_RIGHT,
	CELL_MAX
}CELL_TYPE;

class Cell
{
protected:
	D3DXVECTOR2		pos_ = D3DXVECTOR2(0.0f, 0.0f);	//位置ベクトル
	D3DXVECTOR2		size_ = D3DXVECTOR2(96.0f, 96.0f);	//サイズ
	D3DXCOLOR		color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//頂点カラー
	int texNo_ = 0;
	CELL_TYPE type_ = CELL_NONE;
	POLE pole_ = POLE_NONE;

public:
	Cell();
	Cell(CELL_TYPE type);
	Cell(D3DXVECTOR2 pos, CELL_TYPE type);
	Cell(D3DXVECTOR2 pos, D3DXCOLOR color, CELL_TYPE type);
	virtual ~Cell() = default;
	D3DXVECTOR2 GetPos() { return pos_; }
	D3DXVECTOR2 GetSize() { return size_; }
	D3DXCOLOR GetColor() { return color_; }
	int GetTexture() { return texNo_; }
	POLE GetPole() { return pole_; }
	void SetPos(D3DXVECTOR2 pos) { pos_ = pos; }
	void SetSize(D3DXVECTOR2 size) { size_ = size; }
	void SetColor(D3DXCOLOR color) { color_ = color; }
	void SetTexture(int texNo) { texNo_ = texNo; }
	CELL_TYPE GetType() { return type_; }
	void SetType(CELL_TYPE type) { type_ = type; }

	virtual void Update() = 0;
	virtual void Draw();
};