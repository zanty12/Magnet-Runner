#include "cell.h"
#include "camera.h"
#include "scenemngr.h"
#include "game.h"

Camera* camera = nullptr;

Cell::Cell() {
	camera = ((Game*)(((Scenemngr*)GetSceneMngrInstance())->GetScene()))->GetCamera();
}
Cell::Cell(CELL_TYPE type) :type_(type) {
	camera = ((Game*)(((Scenemngr*)GetSceneMngrInstance())->GetScene()))->GetCamera();
}
Cell::Cell(D3DXVECTOR2 pos, CELL_TYPE type) :pos_(pos), type_(type) {
	camera = ((Game*)(((Scenemngr*)GetSceneMngrInstance())->GetScene()))->GetCamera();
}
Cell::Cell(D3DXVECTOR2 pos, D3DXCOLOR color, CELL_TYPE type) :pos_(pos), color_(color), type_(type) {
	camera = ((Game*)(((Scenemngr*)GetSceneMngrInstance())->GetScene()))->GetCamera();
}

void Cell::Draw()
{
	if (camera->InCamera(pos_)) {
		float DiffX = camera->GetPos().x - SCREEN_WIDTH / 2;
		float DiffY = camera->GetPos().y - SCREEN_HEIGHT / 2;
		if (DiffX < 0)
			DiffX = 0;
		if (DiffY < 0)
			DiffY = 0;
		DrawSpriteColor(texNo_,
			pos_.x - DiffX, pos_.y - DiffY,
			size_.x, size_.y,
			0.0f, 0.0f,//UV’l‚ÌŽn“_
			1.0f, 1.0,
			color_.r, color_.g, color_.b, color_.a);
	}
}