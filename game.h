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
	const char* fileName_ = "data/MAP/map2.csv";

public:
	Game() = default;
	~Game();
	Game(Scenemngr* scenemngr) :Scene(scenemngr) {}
	void Init() override;
	void Update()override;
	void Draw()override;
	void LoadMap(const char* fileName) { fileName_ = fileName; }
	Player* GetPlayer() { return player_; }
	Mapmngr* GetMapmngr() { return mapmngr_; }
	Camera* GetCamera() { return camera_; }
}
;