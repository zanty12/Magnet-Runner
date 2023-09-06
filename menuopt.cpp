#include "menuopt.h"
#include "text.h"
#include "sprite.h"
#include "input.h"

void Menuopt::Draw() {
	if (!chosen_)
		DrawSpriteColor(bgTex_,
			pos_.x, pos_.y,
			350.0f, 420.0f,
			0.0f, 0.0f,//UV値の始点
			1.0f, 1.0,
			1.0f, 1.0f, 1.0f, 1.0f
		);
	else {
		DrawSpriteColor(bgTex_,
			pos_.x, pos_.y,
			350.0f, 420.0f,
			0.0f, 0.0f,//UV値の始点
			1.0f, 1.0,
			1.0f, 0.0f, 0.0f, 1.0f
		);
	}
	DrawSprite(levelTex_,
				pos_.x, pos_.y-50.0f,
				315.0f, 220.0f,
				0.0f, 0.0f,//UV値の始点
				1.0f, 1.0
		);
	float textx = GetTextWidth(level_, 0.5f);
	textx = (350.0f - textx) / 2;
	PrintText(level_, D3DXVECTOR2(pos_.x - 350.0f / 2 + textx, pos_.y+100.0f), 0.5f);
}
