#include "scenemngr.h"

Scenemngr::Scenemngr()
{
	switch (sceneNo_) {
	case SCENE_TITLE:
		//scene_ = new Title();
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
}

Scenemngr::~Scenemngr()
{
	delete scene_;
}



void Scenemngr::SetScene(SCENENO sceneNo)
{
	if (sceneNo != sceneNo_) {
		delete scene_;
		switch (sceneNo) {
		case SCENE_TITLE:
			//scene_ = new Title();
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
	}
}
