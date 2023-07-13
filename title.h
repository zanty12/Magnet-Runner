#pragma once
#include "scenemodules.h"
#include "scene.h"
#include "texture.h"

class Title : public Scene
{
private:
	int titleTex_ = 0;
	int bgTex_ = 0;
public:
	Title() = default;
	Title(Scenemngr* scenemngr) :Scene(scenemngr) {}
	~Title() = default;

	void Init();
	void Update();
	void Draw();

};