#pragma once
#include "gamemodules.h"
#include "scene.h"
class Fail :
    public Scene
{
private:
    int bgTex_ = 0;
public:
    Fail(Scenemngr* scenemngr) :Scene(scenemngr) {}
    ~Fail() = default;
    void Init();
    void Update();
    void Draw();
};

