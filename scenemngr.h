#pragma once
#include "main.h"
#include "scene.h"
#include "game.h"
enum SCENENO {
	SCENE_TITLE,
	SCENE_MENU,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_MAX
};


class Scenemngr
{
private:
	SCENENO sceneNo_ = SCENE_GAME;
	Scene* scene_ = nullptr;

public:
	Scenemngr();
	~Scenemngr();
	void Init() { scene_->Init(); }
	void Update() { scene_->Update(); }
	void Draw() { scene_->Draw(); }
	void SetScene(SCENENO sceneNo);
	SCENENO GetSceneNo() { return sceneNo_; }
	Scene* GetScene() { return scene_; }
};

