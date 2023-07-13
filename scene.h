#pragma once
#include "scenemodules.h"
#include "scenemngr.h"

class Scene
{
protected:
	Scenemngr* mngr_ = nullptr;

public:
	Scene() = default;
	Scene(Scenemngr* mngr) : mngr_(mngr) {}
	~Scene() = default;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void* GetInstance() { return (void*)this; }
};

