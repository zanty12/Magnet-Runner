#pragma once
#include "main.h"
#include "scene.h"
#include "mapmngr.h"
#include "player.h"
#include "camera.h"

class Game : public Scene
{
private:
	Player* player_ = nullptr;
	Mapmngr* mapmngr_ = nullptr;
	Camera* camera_ = nullptr;

public:
	Game() = default;
	~Game();
	Game(Scenemngr* scenemngr) :Scene(scenemngr) {}
	void Init() override;
	void Init(const char* fileName);
	void Update()override;
	void Draw()override;
	Player* GetPlayer() { return player_; }
	Mapmngr* GetMapmngr() { return mapmngr_; }
	Camera* GetCamera() { return camera_; }
}
;
