#include "game.h"
#include "polygon.h"
#include "bullet.h"
#include "scenemngr.h"
#include "text.h"
#include <sstream>

Game::~Game() {
	delete player_;
	delete mapmngr_;
	delete camera_;
	UninitPolygon();
}

void Game::Init() {
	InitPolygon();
	InitBullet();
	mapmngr_ = new Mapmngr();
	player_ = new Player();
	camera_ = new Camera();

	mapmngr_->LoadMap(fileName_);
	camera_->Init(player_, mapmngr_);
	player_->Init(mapmngr_, camera_);
}

void Game::Update()
{
	UpdatePolygon();

	player_->Update();
	camera_->Update();

	UpdateBullet();
	int life = player_->GetLife();
	if (life == 0) {
		mngr_->SetScene(SCENE_RESULT_FAIL);
		return;
	}
	bool isClear = player_->GetIsClear();
	if (isClear) {
		mngr_->SetScene(SCENE_RESULT_CLEAR);
		return;
	}
}

void Game::Draw()
{
	//DrawPolygon();
	ClearText();
	int life = player_->GetLife();
	std::stringstream ss;
	ss << life;
	std::string str = ss.str();
	

	player_->Draw();
	mapmngr_->DrawMap();
	//g_Camera->Draw();

	DrawBullet();
	PrintText(str, D3DXVECTOR2(100.0f, 100.0f), 0.5);
}