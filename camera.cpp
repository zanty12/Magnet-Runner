#include "camera.h"

#include "sprite.h"

Camera::Camera()
{
	Player_ = (Player*)GetPlayerInstance();
	Mapmngr_ = (Mapmngr*)GetMapMngrInstance();
	TexNo_ = LoadTexture((char*)"data/TEXTURE/camera.png");
	Pos_ = D3DXVECTOR2(Player_->GetPos().x, Player_->GetPos().y - 300.0f);
}

void Camera::Update()
{
	//move the camera with the player if the player passes border x or y on both sides
	if (Player_->GetPos().x > Pos_.x + MOVE_BORDER_X && Pos_.x < 96 * Mapmngr_->GetMap()->GetWidth() - ScreenSize_.x / 2) {
		Pos_.x = Player_->GetPos().x - MOVE_BORDER_X;
	}
	if (Player_->GetPos().x < Pos_.x - MOVE_BORDER_X && Pos_.x > 0) {
		Pos_.x = Player_->GetPos().x + MOVE_BORDER_X;
	}
	if (Player_->GetPos().y > Pos_.y + MOVE_BORDER_Y && Pos_.y < 96 * (Mapmngr_->GetMap()->GetHeight()- 2)) {
		Pos_.y = Player_->GetPos().y - MOVE_BORDER_Y;
	}
	if (Player_->GetPos().y < Pos_.y - MOVE_BORDER_Y && Pos_.y > 0) {
		Pos_.y = Player_->GetPos().y + MOVE_BORDER_Y;
	}
}

void Camera::Draw()
{
	DrawSpriteColor(TexNo_,
		Pos_.x, Pos_.y,
		ScreenSize_.x, ScreenSize_.y,
		0.0f, 0.0f,//UV’l‚ÌŽn“_
		1.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 0.3f);
}

bool Camera::InCamera(D3DXVECTOR2 pos)
{
	//check if the object is in the camera or in the buffer zone
	if (pos.x  > Pos_.x - ScreenSize_.x /2 - RENDER_BUFFER && pos.x < Pos_.x + ScreenSize_.x/2 + RENDER_BUFFER) {
		if (pos.y  > Pos_.y- ScreenSize_.y/2 - RENDER_BUFFER && pos.y < Pos_.y + ScreenSize_.y/2 + RENDER_BUFFER) {
			return true;
		}
	}
	return false;
}
