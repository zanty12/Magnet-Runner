#pragma once

#include "main.h"
#include "renderer.h"
#include "sprite.h"

class GameObject
{

protected:
	D3DXVECTOR2		Pos_ = D3DXVECTOR2(0.0f, 0.0f);	//位置ベクトル
	D3DXVECTOR2		Size_ = D3DXVECTOR2(0.0f, 0.0f);	//サイズ
	D3DXCOLOR		Color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//頂点カラー

	int TexNo_ = 0;
	float U_ = 0.0f;
	float V_ = 0.0f;

public:
	GameObject() = default;
	GameObject(D3DXVECTOR2 pos) :Pos_(pos) {}
	GameObject(D3DXVECTOR2 pos, D3DXVECTOR2 size) :Pos_(pos), Size_(size) {}
	GameObject(D3DXVECTOR2 pos,D3DXCOLOR color) :Pos_(pos), Color_(color) {}
	GameObject(D3DXVECTOR2 pos, D3DXVECTOR2 size, D3DXCOLOR color) :Pos_(pos), Size_(size), Color_(color) {}
	virtual ~GameObject() = default;
	D3DXVECTOR2 GetPos() { return Pos_; }
	D3DXVECTOR2 GetSize() { return Size_; }
	D3DXCOLOR GetColor() { return Color_; }
	int GetTexture() { return TexNo_; }
	float GetU() { return U_; }
	float GetV() { return V_; }
	void SetPos(D3DXVECTOR2 pos) { Pos_ = pos; }
	void SetSize(D3DXVECTOR2 size) { Size_ = size; }
	void SetColor(D3DXCOLOR color) { Color_ = color; }
	void SetTexture(int texNo) { TexNo_ = texNo; }
	void SetU(float u) { U_ = u; }
	void SetV(float v) { V_ = v; }

	virtual void Update() = 0;
	virtual void Draw() {
		DrawSpriteColor(TexNo_,
			Pos_.x, Pos_.y,
			Size_.x, Size_.y,
			U_, V_,//UV値の始点
			1.0f, 1.0,
			Color_.r, Color_.g, Color_.b, Color_.a);
	}

};

