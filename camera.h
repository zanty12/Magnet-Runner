#pragma once
#include "main.h"
#include "player.h"
#include "mapmngr.h"
#include "texture.h"

#define MOVE_BORDER_X 600.0f //the camera will move with the player if the player touches the border
#define MOVE_BORDER_Y 350.0f
#define RENDER_BUFFER 100.0f //the camera will render the objects in the buffer zone

class Camera
{
private:
	Player* Player_;
	Mapmngr* Mapmngr_;
	D3DXVECTOR2 Pos_;
	D3DXVECTOR2 ScreenSize_ = D3DXVECTOR2(1920.0f,1080.0f);
	int TexNo_;
public:
	Camera();
	~Camera() = default;
	void Update();
	void Draw();
	bool InCamera(D3DXVECTOR2 pos);

};

