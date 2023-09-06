#include "game.h"
#include "timer.h"
#include "bullet.h"
#include "scenemngr.h"
#include "text.h"
#include "texture.h"
#include "sound.h"
#include "sprite.h"
#include <sstream>

int guideTexture;

Game::~Game() {
	delete player_;
	delete mapmngr_;
	delete camera_;
	UninitTimer();
}

void Game::Init() {
	InitTimer();
	mapmngr_ = new Mapmngr();
	player_ = new Player();
	camera_ = new Camera();
	guideTexture = LoadTexture((char*)"data/TEXTURE/control.png");
	mapmngr_->LoadMap(fileName_);
	camera_->Init(player_, mapmngr_);
	player_->Init(mapmngr_, camera_,mapmngr_->GetMap()->GetStart());
	bgmNo_ = LoadSound((char*)"data/SOUND/game.wav");
	PlaySound(bgmNo_, -1);
}

void Game::Update()
{
	UpdateTimer();

	player_->Update();
	camera_->Update();
	mapmngr_->UpdateMap();

	int life = player_->GetLife();
	if (life == 0) {
		mngr_->SetScene(SCENE_RESULT_FAIL);
		return;
	}
	bool isClear = player_->GetIsClear();
	if (isClear) {
		mngr_->SetScene(SCENE_RESULT_CLEAR,GetTimer());
		return;
	}
}

void Game::Draw()
{
	
	ClearText();
	camera_->Draw();
	player_->Draw();
	mapmngr_->DrawMap();
	
	int life = player_->GetLife();
	std::stringstream ss;
	ss <<"life: " << life;
	std::string str = ss.str();
	PrintText(str, D3DXVECTOR2(100.0f, 100.0f), 0.5);
	DrawTimer();
	DrawSprite(guideTexture, 500.0f, 200.0f, 737.0f, 96.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	DrawText();
}

