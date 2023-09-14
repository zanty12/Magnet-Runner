#include "menu.h"
#include "texture.h"
#include "text.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"

Menu::~Menu()
{
	for (auto& opt : options) {
		delete opt;
	}
	options.clear();
}


void Menu::Init()
{
	bgTex_ = LoadTexture((char*)"data/TEXTURE/menu_bg.png");
	options.push_back(new Menuopt(LoadTexture((char*)"data/TEXTURE/menuopt_bg.png"), LoadTexture((char*)"data/TEXTURE/level1.png"), std::string("startup"), std::string("data/MAP/map1.csv"), 380.0f, 400.0f));
	options.push_back(new Menuopt(LoadTexture((char*)"data/TEXTURE/menuopt_bg.png"), LoadTexture((char*)"data/TEXTURE/level2.png"), std::string("dash"), std::string("data/MAP/map2.csv"), 780.0f, 400.0f));
	options.push_back(new Menuopt(LoadTexture((char*)"data/TEXTURE/menuopt_bg.png"), LoadTexture((char*)"data/TEXTURE/level3.png"), std::string("danger"), std::string("data/MAP/map3.csv"), 1180.0f, 400.0f));
	options.push_back(new Menuopt(LoadTexture((char*)"data/TEXTURE/menuopt_bg.png"), LoadTexture((char*)"data/TEXTURE/level4.png"), std::string("vertigo"), std::string("data/MAP/map4.csv"), 1580.0f, 400.0f));
	options.front()->SetChosen(true);
	bgmNo_ = LoadSound((char*)"data/SOUND/menu.wav");
	chooseSe_ = LoadSound((char*)"data/SOUND/choose.wav");
	decideSe_ = LoadSound((char*)"data/SOUND/decide.wav");	
	PlaySound(bgmNo_, -1);

}

void Menu::Update()
{
	if (GetKeyboardTrigger(DIK_D)) {
		//change the chosen option
		PlaySound(chooseSe_, 0);
		for (int i = 0; i < options.size(); i++) {
			if (options[i]->GetChosen()) {
				options[i]->SetChosen(false);
				if (i == options.size() - 1) {
					options.front()->SetChosen(true);
					break;
				}
				else {
					i++;
					options[i]->SetChosen(true);
					break;
				}
			}
		}
	}
	else if (GetKeyboardTrigger(DIK_A)) {
		//change the chosen option
		PlaySound(chooseSe_, 0);
		for (int i = 0; i < options.size(); i++) {
			if (options[i]->GetChosen()) {
				options[i]->SetChosen(false);
				if (i == 0) {
					options.back()->SetChosen(true);
					break;
				}
				else {
					i--;
					options[i]->SetChosen(true);
					break;
				}
			}
		}
	}
	else if (GetKeyboardTrigger(DIK_RETURN)) {
		//change the scene
		PlaySound(decideSe_, 0);
		for (auto& opt : options) {
			if (opt->GetChosen()) {
				mngr_->SetScene(SCENE_GAME, opt->GetMapFile());
				break;
			}
		}
	}
}

void Menu::Draw()
{
	ClearText();
	PrintText(std::string("select stage"), D3DXVECTOR2(500.0f, 100.0f));
	DrawSprite(bgTex_,
				SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				0.0f, 0.0f,//UV’l‚ÌŽn“_
				1.0f, 1.0
		);
	for (auto& opt : options) {
		opt->Draw();
	}
	DrawText();
}
