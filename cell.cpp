#include "cell.h"
#include "camera.h"

void Cell::Draw()
{
	Camera* camera = (Camera*)GetCameraInstance();
	if (camera->InCamera(Pos_)) {
		DrawSpriteColor(TexNo_,
			Pos_.x, Pos_.y,
			Size_.x, Size_.y,
			0.0f, 0.0f,//UV’l‚ÌŽn“_
			1.0f, 1.0,
			Color_.r, Color_.g, Color_.b, Color_.a);
	}
		
}
