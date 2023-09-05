#include "title.h"
#include "scenemngr.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
#include "text.h"
#include "sound.h"

void Title::Init()
{
	titleTex_ = LoadTexture((char*)"data/TEXTURE/title.png");
	bgTex_ = LoadTexture((char*)"data/TEXTURE/title_bg.png");
	
	bgmNo_ = LoadSound((char*)"data/SOUND/menu.wav");
	PlaySound(bgmNo_, -1);
}

void Title::Update()
{
	if (GetKeyboardPress(DIK_RETURN)) {
		mngr_->SetScene(SCENE_MENU);
	}
}

void Title::Draw()
{
	ClearText();
	PrintText(std::string("press enter"), D3DXVECTOR2(520.0f, 960.0f));
	DrawSprite(bgTex_,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
	DrawSprite(titleTex_,
		960, 264.0f,
		1024.0f, 339.0f,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
	
	
}