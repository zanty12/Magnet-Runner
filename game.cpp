#include "game.h"
#include "polygon.h"
#include "bullet.h"
#include "scenemngr.h"

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
	
	mapmngr_->LoadMap("data/MAP/map2.csv");
	camera_->SetPlayer(player_);
	camera_->SetMapmngr(mapmngr_);
	player_->Init();
}

void Game::Init(const char* fileName)
{
	InitPolygon();
	InitBullet();
	mapmngr_ = new Mapmngr();
	player_ = new Player();
	camera_ = new Camera();
	
	mapmngr_->LoadMap(fileName);
	camera_->SetPlayer(player_);
	camera_->SetMapmngr(mapmngr_);
	player_->Init();
}

void Game::Update()
{
	UpdatePolygon();

	player_->Update();
	camera_->Update();

	UpdateBullet();
}

void Game::Draw()
{

	DrawPolygon();

	player_->Draw();
	mapmngr_->DrawMap();
	//g_Camera->Draw();

	DrawBullet();
}
