#pragma once
#include "scenemodules.h"
#include "scene.h"
#include<string>

class Result :
    public Scene
{
private:
    int bgTex_ = 0;
	std::string result_;
public:
	Result(Scenemngr* scenemngr, std::string result) :Scene(scenemngr) { result_ = result; }
	~Result() = default;
	void Init();
	void Update();
	void Draw();
};

