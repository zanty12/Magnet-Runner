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
	float bottomBorder = 96.0f * (Mapmngr_->GetMap()->GetHeight()) - ScreenSize_.y / 2;
	float rightBorder = 96.0f * (Mapmngr_->GetMap()->GetWidth()) - ScreenSize_.x / 2;
	
	//move the camera with the player if the player passes border x or y on both sides
	if (Player_->GetPos().x > Pos_.x + MOVE_BORDER_X ) {
		Pos_.x = Player_->GetPos().x - MOVE_BORDER_X;
	}
	else if (Player_->GetPos().x < Pos_.x - MOVE_BORDER_X ) {
		Pos_.x = Player_->GetPos().x + MOVE_BORDER_X;
	}
	if (Player_->GetPos().y < Pos_.y - MOVE_BORDER_Y && Pos_.y > ScreenSize_.y / 2) {
		Pos_.y = Player_->GetPos().y + MOVE_BORDER_Y;
	}
	else if (Player_->GetPos().y > Pos_.y + MOVE_BORDER_Y && Pos_.y < bottomBorder) {
			Pos_.y = Player_->GetPos().y - MOVE_BORDER_Y;
	}
	if (Pos_.x < ScreenSize_.x / 2) {
		Pos_.x = ScreenSize_.x / 2;
	}
	else if (Pos_.x > rightBorder) {
		Pos_.x = rightBorder;
	}
	Cell* temp = Mapmngr_->GetMap()->GetCell(16,16);
	if (Pos_.y < ScreenSize_.y / 2) {
		Pos_.y = ScreenSize_.y / 2;
	}
	else if (Pos_.y > bottomBorder) {
		Pos_.y = bottomBorder;
	}
}

void Camera::Draw()
{
	float DiffX = Pos_.x - SCREEN_WIDTH / 2;
	float DiffY = Pos_.y - SCREEN_HEIGHT / 2;
	if (DiffX < 0)
		DiffX = 0;
	if (DiffY < 0)
		DiffY = 0;
	DrawSpriteColor(TexNo_,
		Pos_.x-DiffX, Pos_.y-DiffY,
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
