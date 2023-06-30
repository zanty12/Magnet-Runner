#pragma once
#include "sprite.h"

class Cell
{
protected:
	D3DXVECTOR2		Pos_ = D3DXVECTOR2(0.0f, 0.0f);	//位置ベクトル
	D3DXVECTOR2		Size_ = D3DXVECTOR2(96.0f, 96.0f);	//サイズ
	D3DXCOLOR		Color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//頂点カラー
	int TexNo_ = 0;


public:
	Cell() = default;
	~Cell() = default;
	Cell(D3DXVECTOR2 pos) :Pos_(pos) {}
	Cell(D3DXVECTOR2 pos, D3DXCOLOR color) :Pos_(pos), Color_(color) {}
	D3DXVECTOR2 GetPos() { return Pos_; }
	D3DXVECTOR2 GetSize() { return Size_; }
	D3DXCOLOR GetColor() { return Color_; }
	int GetTexture() { return TexNo_; }
	void SetPos(D3DXVECTOR2 pos) { Pos_ = pos; }
	void SetSize(D3DXVECTOR2 size) { Size_ = size; }
	void SetColor(D3DXCOLOR color) { Color_ = color; }
	void SetTexture(int texNo) { TexNo_ = texNo; }

	virtual void Update() = 0;
	virtual void Draw() {
		DrawSpriteColor(TexNo_,
			Pos_.x, Pos_.y,
			Size_.x, Size_.y,
			0.0f, 0.0f,//UV値の始点
			1.0f, 1.0,
			Color_.r, Color_.g, Color_.b, Color_.a);
	}
};