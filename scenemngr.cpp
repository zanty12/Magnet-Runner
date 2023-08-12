#include "scenemngr.h"
#include "scene.h"
#include "title.h"
#include "game.h"
#include "text.h"

Scenemngr::Scenemngr()
{
	switch (sceneNo_) {
	case SCENE_TITLE:
		scene_ = new Title(this);
		break;
	case SCENE_MENU:
		//scene_ = new Menu();
		break;
	case SCENE_GAME:
		scene_ = new Game(this);
		break;
	case SCENE_RESULT:
		//scene_ = new Result();
		break;
	default:
		break;
	}
}

Scenemngr::~Scenemngr()
{
	delete scene_;
}

void Scenemngr::Init() {
	scene_->Init();
	InitText();
}
void Scenemngr::Update() {
	scene_->Update();
}
void Scenemngr::Draw() {
	scene_->Draw();
	DrawText();
}

void Scenemngr::SetScene(SCENENO sceneNo)
{
	if (sceneNo != sceneNo_) {
		sceneNo_ = sceneNo;
		delete scene_;
		ClearText();
		switch (sceneNo) {
		case SCENE_TITLE:
			scene_ = new Title();
			break;
		case SCENE_MENU:
			//scene_ = new Menu();
			break;
		case SCENE_GAME:
			scene_ = new Game();
			break;
		case SCENE_RESULT:
			//scene_ = new Result();
			break;
		default:
			break;
		}
		scene_->Init();
	}
}