#include "result.h"
#include "texture.h"
#include "text.h"
#include "input.h"
#include "sprite.h"
#include <sstream>
#include "sound.h"

void Result::Init()
{
	bgTex_ = LoadTexture((char*)"data/TEXTURE/result_bg.png");
	bgmNo_ = LoadSound((char*)"data/SOUND/win.wav");
	PlaySound(bgmNo_, -1);
	
}

void Result::Update()
{
	if (GetKeyboardPress(DIK_RETURN)) {
		mngr_->SetScene(SCENE_MENU);
	}
}

void Result::Draw() {
	ClearText();

	DrawSprite(bgTex_,
				SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				0.0f, 0.0f,//UV’l‚ÌŽn“_
				1.0f, 1.0
		);
	PrintText(std::string("clear"), D3DXVECTOR2(520.0f, 800.0f));
	std::stringstream ss;
	ss << "time: " << result_;
	std::string str = ss.str();
	PrintText(str, D3DXVECTOR2(400.0f, 900.0f));
	DrawText();
}