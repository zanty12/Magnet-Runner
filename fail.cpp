#include "fail.h"
#include "texture.h"
#include "text.h"
#include "input.h"
#include "sprite.h"

void Fail::Init()
{
	bgTex_ = LoadTexture((char*)"data/TEXTURE/fail_bg.png");
	PrintText(std::string("you failed"), D3DXVECTOR2(520.0f, 960.0f));
}

void Fail::Update()
{
	if (GetKeyboardPress(DIK_RETURN)) {
		mngr_->SetScene(SCENE_MENU);
	}
}

void Fail::Draw() {
	DrawSprite(bgTex_,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,//UV’l‚ÌŽn“_
		1.0f, 1.0
	);
}
