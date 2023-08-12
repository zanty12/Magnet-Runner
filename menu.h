#pragma once
#include "scene.h"
#include "menuopt.h"
#include <vector>
class Menu :
    public Scene
{
private:
	int bgTex_ = 0;
	std::vector<Menuopt*> options;
	
public:
	Menu() = default;
	Menu(Scenemngr* scenemngr) :Scene(scenemngr) {}
	~Menu();
	void Init();
	void Update();
	void Draw();
};

