#include "cell.h"
#include "camera.h"

void Cell::Draw()
{
	Camera* camera = (Camera*)GetCameraInstance();
	if (camera->InCamera(Pos_)) {
		float DiffX = camera->GetPos().x - SCREEN_WIDTH / 2;
		float DiffY = camera->GetPos().y - SCREEN_HEIGHT / 2;
		if (DiffX < 0)
			DiffX = 0;
		if (DiffY < 0)
			DiffY = 0;
		DrawSpriteColor(TexNo_,
			Pos_.x - DiffX, Pos_.y - DiffY,
			Size_.x, Size_.y,
			0.0f, 0.0f,//UV’l‚ÌŽn“_
			1.0f, 1.0,
			Color_.r, Color_.g, Color_.b, Color_.a);
	}
		
}
