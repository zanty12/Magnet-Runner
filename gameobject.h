#pragma once

#include "main.h"
#include "renderer.h"
#include "sprite.h"

typedef enum {
	POLE_NONE = 0,
	POLE_PLUS,
	POLE_MINUS,
	POLE_MAX
}POLE;

class GameObject
{
protected:
	D3DXVECTOR2		pos_ = D3DXVECTOR2(0.0f, 0.0f);	//位置ベクトル
	D3DXVECTOR2		size_ = D3DXVECTOR2(0.0f, 0.0f);	//サイズ
	D3DXCOLOR		color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//頂点カラー
	POLE pole_ = POLE_NONE;

	int texNo_ = 0;
	float u_ = 0.0f;
	float v_ = 0.0f;

public:
	GameObject() = default;
	GameObject(D3DXVECTOR2 pos) :pos_(pos) {}
	GameObject(D3DXVECTOR2 pos, D3DXVECTOR2 size) :pos_(pos), size_(size) {}
	GameObject(D3DXVECTOR2 pos, D3DXCOLOR color) :pos_(pos), color_(color) {}
	GameObject(D3DXVECTOR2 pos, D3DXVECTOR2 size, D3DXCOLOR color) :pos_(pos), size_(size), color_(color) {}
	virtual ~GameObject() = default;
	D3DXVECTOR2 GetPos() { return pos_; }
	D3DXVECTOR2 GetSize() { return size_; }
	D3DXCOLOR GetColor() { return color_; }
	int GetTexture() { return texNo_; }
	float GetU() { return u_; }
	float GetV() { return v_; }
	POLE GetPole() { return pole_; }
	void SetPos(D3DXVECTOR2 pos) { pos_ = pos; }
	void SetSize(D3DXVECTOR2 size) { size_ = size; }
	void SetColor(D3DXCOLOR color) { color_ = color; }
	void SetTexture(int texNo) { texNo_ = texNo; }
	void SetU(float u) { u_ = u; }
	void SetV(float v) { v_ = v; }
	void SetPole(POLE pole) { pole_ = pole; }

	virtual void Update() = 0;
	virtual void Draw() {
		DrawSpriteColor(texNo_,
			pos_.x, pos_.y,
			size_.x, size_.y,
			u_, v_,//UV値の始点
			1.0f, 1.0,
			color_.r, color_.g, color_.b, color_.a);
	}
};
