#include "title.h"
#include "scenemngr.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
void Title::Init()
{
	titleTex_ = LoadTexture((char*)"data/TEXTURE/title.png");
	bgTex_ = LoadTexture((char*)"data/TEXTURE/title_bg.png");
}

void Title::Update()
{
	if (GetKeyboardPress(DIK_SPACE))
	{
		mngr_->SetScene(SCENE_GAME);
	}
}

void Title::Draw()
{
	DrawSprite(bgTex_,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
	DrawSprite(titleTex_,
		960, 264.0f,
		991.0f, 264.0f,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
}