#pragma once
#include "main.h"
#include "gamemodules.h"
#include "texture.h"

#define MOVE_BORDER_X 300.0f //the camera will move with the player if the player touches the border
#define MOVE_BORDER_Y 300.0f
#define RENDER_BUFFER 100.0f //the camera will render the objects in the buffer zone

class Camera
{
private:
	Player* player_ = nullptr;
	Mapmngr* mapmngr_ = nullptr;
	D3DXVECTOR2 pos_;
	D3DXVECTOR2 screenSize_ = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	int texNo_;

public:
	Camera();
	~Camera() = default;
	void Init(Player* player, Mapmngr* mapmngr);
	void Update();
	void Draw();
	bool InCamera(D3DXVECTOR2 pos);
	D3DXVECTOR2 GetPos() { return pos_; };
	Player* GetPlayer() { return player_; };
};