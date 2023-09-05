#include "camera.h"
#include "sprite.h"

#include "player.h"
#include "mapmngr.h"

Camera::Camera()
{
	texNo_ = LoadTexture((char*)"data/TEXTURE/camera.png");
	pos_ = D3DXVECTOR2(0, 0);
}

void Camera::Init(Player* player, Mapmngr* mapmngr) {
	player_ = player;
	mapmngr_ = mapmngr;
}

void Camera::Update()
{
	float bottomBorder = 96.0f * (mapmngr_->GetMap()->GetHeight()) - screenSize_.y / 2;
	float rightBorder = 96.0f * (mapmngr_->GetMap()->GetWidth()) - screenSize_.x / 2;

	//move the camera with the player if the player passes border x or y on both sides
	if (player_->GetPos().x > pos_.x + MOVE_BORDER_X) {
		pos_.x = player_->GetPos().x - MOVE_BORDER_X;
	}
	else if (player_->GetPos().x < pos_.x - MOVE_BORDER_X) {
		pos_.x = player_->GetPos().x + MOVE_BORDER_X;
	}
	if (player_->GetPos().y < pos_.y - MOVE_BORDER_Y && pos_.y > screenSize_.y / 2) {
		pos_.y = player_->GetPos().y + MOVE_BORDER_Y;
	}
	else if (player_->GetPos().y > pos_.y + MOVE_BORDER_Y && pos_.y < bottomBorder) {
		pos_.y = player_->GetPos().y - MOVE_BORDER_Y;
	}
	if (pos_.x < screenSize_.x / 2) {
		pos_.x = screenSize_.x / 2;
	}
	else if (pos_.x > rightBorder) {
		pos_.x = rightBorder;
	}
	Cell* temp = mapmngr_->GetMap()->GetCell(16, 16);
	if (pos_.y < screenSize_.y / 2) {
		pos_.y = screenSize_.y / 2;
	}
	else if (pos_.y > bottomBorder) {
		pos_.y = bottomBorder;
	}
}

void Camera::Draw()
{
	float DiffX = pos_.x - SCREEN_WIDTH / 2;
	float DiffY = pos_.y - SCREEN_HEIGHT / 2;
	if (DiffX < 0)
		DiffX = 0;
	if (DiffY < 0)
		DiffY = 0;
	DrawSpriteColor(texNo_,
		pos_.x - DiffX, pos_.y - DiffY,
		screenSize_.x, screenSize_.y,
		0.0f, 0.0f,//UVfl???ng_
		1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 0.5f);
}

bool Camera::InCamera(D3DXVECTOR2 pos)
{
	//check if the object is in the camera or in the buffer zone
	if (pos.x > pos_.x - screenSize_.x / 2 - RENDER_BUFFER && pos.x < pos_.x + screenSize_.x / 2 + RENDER_BUFFER) {
		if (pos.y > pos_.y - screenSize_.y / 2 - RENDER_BUFFER && pos.y < pos_.y + screenSize_.y / 2 + RENDER_BUFFER) {
			return true;
		}
	}
	return false;
}