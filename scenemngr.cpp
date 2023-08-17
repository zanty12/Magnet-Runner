#include "scenemngr.h"
#include "scene.h"
#include "title.h"
#include "game.h"
#include "menu.h"
#include "text.h"
#include "fail.h"

Scenemngr::Scenemngr()
{
	switch (sceneNo_) {
	case SCENE_TITLE:
		scene_ = new Title(this);
		break;
	case SCENE_MENU:
		scene_ = new Menu(this);
		break;
	case SCENE_GAME:
		scene_ = new Game(this);
		break;
	case SCENE_RESULT_FAIL:
		scene_ = new Fail(this);
		break;
	case SCENE_RESULT_CLEAR:
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
			scene_ = new Title(this);
			break;
		case SCENE_MENU:
			scene_ = new Menu(this);
			break;
		case SCENE_GAME:
			scene_ = new Game(this);
			break;
		case SCENE_RESULT_FAIL:
			scene_ = new Fail(this);
			break;
		case SCENE_RESULT_CLEAR:
			//scene_ = new Result();
			break;
		default:
			break;
		}
		scene_->Init();
	}
}

void Scenemngr::SetScene(SCENENO sceneNo, std::string mapFile)
{
	if (sceneNo != sceneNo_) {
		sceneNo_ = sceneNo;
		delete scene_;
		ClearText();
		switch (sceneNo) {
		case SCENE_TITLE:
			scene_ = new Title(this);
			break;
		case SCENE_MENU:
			scene_ = new Menu(this);
			break;
		case SCENE_GAME:
			scene_ = new Game(this);
			((Game*)scene_)->LoadMap(mapFile.c_str());
			break;
		case SCENE_RESULT_FAIL:
			scene_ = new Fail(this);
			break;
		case SCENE_RESULT_CLEAR:
			//scene_ = new Result();
			break;
		default:
			break;
		}
		scene_->Init();
	}
}