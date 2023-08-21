#include "game.h"
#include "timer.h"
#include "bullet.h"
#include "scenemngr.h"
#include "text.h"
#include <sstream>

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

	mapmngr_->LoadMap(fileName_);
	camera_->Init(player_, mapmngr_);
	player_->Init(mapmngr_, camera_);
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
	
	player_->Draw();
	mapmngr_->DrawMap();
	
	int life = player_->GetLife();
	std::stringstream ss;
	ss <<"life: " << life;
	std::string str = ss.str();
	PrintText(str, D3DXVECTOR2(100.0f, 100.0f), 0.5);
	DrawTimer();
}

