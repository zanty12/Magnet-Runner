#pragma once
#include "main.h"
#include "scenemodules.h"

class Scenemngr
{
private:
	SCENENO sceneNo_ = SCENE_TITLE;
	Scene* scene_ = nullptr;

public:
	Scenemngr();
	~Scenemngr();
	void Init();
	void Update();
	void Draw();
	void SetScene(SCENENO sceneNo);
	SCENENO GetSceneNo() { return sceneNo_; }
	Scene* GetScene() { return scene_; }
};

