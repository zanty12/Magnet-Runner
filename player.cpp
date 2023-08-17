/*==============================================================================

   プレイヤー管理 [player.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "player.h"
#include "input.h"
#include "sprite.h"
#include "texture.h"
#include "main.h"
#include "bullet.h"
#include "calculations.h"
#include "mapmngr.h"
#include "camera.h"
#include "map.h"
#include "scenemngr.h"
#include <cmath>
#include <algorithm>

//*****************************************************************************
// マクロ定義
//*****************************************************************************

#define ANIME_PTN_YOKO 3
#define ANIME_PTN_TATE 1
#define ANIME_PTN_WAIT 5

#define ANIME_PTN (ANIME_PTN_YOKO * ANIME_PTN_TATE)
#define ANIME_PTN_U (1.0f / ANIME_PTN_YOKO)
#define ANIME_PTN_V (1.0f / ANIME_PTN_TATE)

#define GRAVITY_ACCEL 4.0f
#define MAX_GRAVITY 20.0f
#define JUMP_FORCE -30.0f

#define MAX_SPEED_X 10.0f
#define MAX_SPEED_Y 20.0f
#define BLOCK_EFFECT_RADIUS 7 * CELL_SIZE
#define BLOCK_ACCELX 5.0f
#define BLOCK_ACCELY 10.0f
#define RAY_LENGTH 7 //上下左右のブロックを探す範囲

Player::Player() : GameObject(D3DXVECTOR2(960.0f, 540.0f)) {
	texNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	size_ = D3DXVECTOR2(96.0f, 96.0f);
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel) : GameObject(pos)
{
	vel = vel;
	texNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	size_ = D3DXVECTOR2(96.0f, 96.0f);
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot) : GameObject(pos, color)
{
	vel = vel;
	rot = rot;
	texNo_ = LoadTexture((char*)"data/TEXTURE/majo.png");
	size_ = D3DXVECTOR2(96.0f, 96.0f);
}

void Player::Init(Mapmngr* MapmngrInstance, Camera* CameraInstance) {
	mapmngr_ = MapmngrInstance;
	map_ = mapmngr_->GetMap();
	camera_ = CameraInstance;
}

Player::~Player() = default;

void Player::Update(void)
{
	static bool isAnim = false; // Flag to indicate if animation is active

	// Adjust horizontal velocity
	if (vel_.x < 0.0f)
		vel_.x += 1.0f;
	else if (vel_.x > 0.0f)
		vel_.x -= 1.0f;

	// Apply gravity if enabled
	if (isGravity_) {
		if (vel_.y < MAX_GRAVITY) {
			if (gravState_ == GRAV_HALF)
				vel_.y += GRAVITY_ACCEL / 2;
			else
				vel_.y += GRAVITY_ACCEL;
		}
		if (vel_.y >= MAX_GRAVITY)
			vel_.y = MAX_GRAVITY;
	}
	// Limit horizontal velocity
	if (vel_.x > MAX_SPEED_X)
		vel_.x = MAX_SPEED_X;

	//キーボード
	if (GetKeyboardPress(DIK_SPACE))
	{
		if (!jumped_ && grounded_) {
			vel_.y = JUMP_FORCE;
			jumped_ = true;
			grounded_ = false;
			gravState_ = GRAV_HALF;
		}
	}
	else if (!GetKeyboardPress(DIK_SPACE) && grounded_) {
		jumped_ = false;
	}

	if (GetKeyboardPress(DIK_A))
	{
		vel_.x = -8.0f;
		isAnim = true;
		v_ = 0.25f;
	}
	if (GetKeyboardPress(DIK_D))
	{
		vel_.x = 8.0f;
		isAnim = true;
		v_ = 0.5f;
	}

	if (GetKeyboardPress(DIK_Q))
	{
		pole_ = POLE_MINUS;
		color_ = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	}
	if (GetKeyboardPress(DIK_E))
	{
		pole_ = POLE_PLUS;
		color_ = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}

	if (GetKeyboardPress(DIK_R))
	{
		pole_ = POLE_NONE;
		color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}

	if ((vel_.y != 0.0f && vel_.x < 0.0f) || vel_.x < 0.0f)
		rot_ = atan(vel_.y / vel_.x) - D3DX_PI;
	else if (vel_.x != 0.0f || vel_.y != 0.0f)
		rot_ = atan(vel_.y / vel_.x);

	pos_.x += vel_.x;
	pos_.y += vel_.y;

	//周りのマス取得
	int xIndex = std::floor(pos_.x / size_.x);
	int yIndex = std::floor(pos_.y / size_.y);

	//save the old blocks
	for (int i = 0; i < 5; i++) {
		oldInteractCell_[i] = interactCell_[i];
	}

	Cell* temp = nullptr;
	//up
	for (int i = 1; i <= RAY_LENGTH; i++) {
		if (yIndex - i >= 0)
			temp = map_->GetCell(xIndex, yIndex - i);
		if (temp != nullptr) {
			interactCell_[DIRECTION_UP] = temp;
			break;
		}
		else if (i == RAY_LENGTH) {
			interactCell_[DIRECTION_UP] = nullptr;
			oldInteractCell_[DIRECTION_UP] = nullptr;
		}

	}
	temp = nullptr;
	//down
	for (int i = 1; i <= RAY_LENGTH; i++) {
		if (yIndex + i < map_->GetHeight())
			temp = map_->GetCell(xIndex, yIndex + i);
		if (temp != nullptr) {
			interactCell_[DIRECTION_DOWN] = temp;
			break;
		}
		else if (i == RAY_LENGTH) {
			interactCell_[DIRECTION_DOWN] = nullptr;
			oldInteractCell_[DIRECTION_DOWN] = nullptr;
		}

	}
	temp = nullptr;
	//left
	for (int i = 1; i <= RAY_LENGTH; i++) {
		if (xIndex - i >= 0)
			temp = map_->GetCell(xIndex - i, yIndex);
		if (temp != nullptr) {
			interactCell_[DIRECTION_LEFT] = temp;
			break;
		}
		else if (i == RAY_LENGTH) {
			interactCell_[DIRECTION_LEFT] = nullptr;
			oldInteractCell_[DIRECTION_LEFT] = nullptr;
		}
	}
	temp = nullptr;
	//right
	for (int i = 1; i <= RAY_LENGTH; i++) {
		if (xIndex + i < map_->GetWidth())
			temp = map_->GetCell(xIndex + i, yIndex);
		if (temp != nullptr) {
			interactCell_[DIRECTION_RIGHT] = temp;
			break;
		}
		else if (i == RAY_LENGTH) {
			interactCell_[DIRECTION_RIGHT] = nullptr;
			oldInteractCell_[DIRECTION_RIGHT] = nullptr;
		}

	}
	//center
	interactCell_[DIRECTION_CENTER] = map_->GetCell(xIndex, yIndex);
	oldInteractCell_[DIRECTION_CENTER] = map_->GetCell(xIndex, yIndex);

	for (int i = 0; i < DIRECTION_MAX; i++) {
		CellInteract(interactCell_[i], (DIRECTION)i);
	}

	//画面外に出ないようにする
	if (pos_.x < size_.x / 2)
		pos_.x = size_.x / 2;
	else if (pos_.x > map_->GetWidth() * 96.0f - CELL_SIZE / 2)
		pos_.x = map_->GetWidth() * 96.0f - CELL_SIZE / 2;
	if (pos_.y < 0.0f - size_.y / 2)
		pos_.y = 0.0f - size_.y / 2;
	else if (pos_.y > map_->GetHeight() * 96.0f)
		pos_.y = map_->GetHeight() * 96.0f;

	//ゲームパッド
	if (IsButtonPressed(0, BUTTON_A) || GetKeyboardPress(DIK_TAB))
	{
		//座標のリセット
		pos_.x = SCREEN_WIDTH / 2;
		pos_.y = SCREEN_HEIGHT / 2;
	}

	if (isAnim == true) {
		animeSkipFrame_++;
		if (animeSkipFrame_ > ANIME_PTN_WAIT)
		{
			animeSkipFrame_ = 0;

			animePattern_++;
			if (animePattern_ >= ANIME_PTN)
			{
				animePattern_ = 0;
			}
		}
	}
	else {
		animePattern_ = 1;
	}
	isAnim = false;
	u_ = (animePattern_ % ANIME_PTN_YOKO) * ANIME_PTN_U;
	if (isInvincible_ == true)
		invincibleFrame_--;
	if (invincibleFrame_ <= 0) {
		isInvincible_ = false;
		invincibleFrame_ = 180;
	}
	
}
//=============================================================================
// 描画処理
//=============================================================================
void Player::Draw(void)
{
	//プレイヤーの描画

	float DiffX = camera_->GetPos().x - SCREEN_WIDTH / 2;
	float DiffY = camera_->GetPos().y - SCREEN_HEIGHT / 2;
	if (DiffX < 0)
		DiffX = 0;
	if (DiffY < 0)
		DiffY = 0;
	if (!isInvincible_ || (isInvincible_ && invincibleFrame_ / 20 % 2 == 1))
	DrawSpriteColor(texNo_,
		pos_.x - DiffX, pos_.y - DiffY,
		96.0f, 96.0f,
		u_, v_,//UV値の始点
		ANIME_PTN_U, 0.25f,
		color_.r, color_.g, color_.b, color_.a);
}

//セルの処理判定
void Player::CellInteract(Cell* cell, DIRECTION direction)
{
	if (cell == nullptr)
		return;
	switch (cell->GetType())
	{
	case CELL_BLOCK_NORMAL:
		BlockInteract(cell, direction);
		break;
	case CELL_BLOCK_PLUS:
		PoleBlockInteract(cell, direction);
		break;
	case CELL_BLOCK_MINUS:
		PoleBlockInteract(cell, direction);
		break;
	case CELL_CANNON_UP:
		BlockInteract(cell, direction);
		break;
	case CELL_CANNON_DOWN:
		BlockInteract(cell, direction);
		break;
	case CELL_CANNON_LEFT:
		BlockInteract(cell, direction);
		break;
	case CELL_CANNON_RIGHT:
		BlockInteract(cell, direction);
		break;
	case CELL_SPIKE_UP:
		SpikeInteract(cell, direction);
		break;
	case CELL_SPIKE_DOWN:
		SpikeInteract(cell, direction);
		break;
	case CELL_SPIKE_LEFT:
		SpikeInteract(cell, direction);
		break;
	case CELL_SPIKE_RIGHT:
		SpikeInteract(cell, direction);
		break;
	default:
		break;
	}
}

//通常ブロック処理
void Player::BlockInteract(Cell* cell, DIRECTION direction)
{
	switch (direction) {
	case DIRECTION_DOWN: {
		if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - size_.y / 2;
			grounded_ = true;
			gravState_ = GRAV_NORMAL;
			oldInteractCell_[direction] = cell;
		}
		else
		{
			grounded_ = false;
		}
		break;
	}
	case DIRECTION_UP: {
		if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			pos_.y = cell->GetPos().y + cell->GetSize().y / 2 + size_.y / 2;
			oldInteractCell_[direction] = cell;
		}
		break;
	}
	case DIRECTION_LEFT: {
		if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			pos_.x = cell->GetPos().x + cell->GetSize().x / 2 + size_.x / 2;
			oldInteractCell_[direction] = cell;
		}
		break;
	}
	case DIRECTION_RIGHT: {
		if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			pos_.x = cell->GetPos().x - cell->GetSize().x / 2 - size_.x / 2;
			oldInteractCell_[direction] = cell;
		}
		break;
	}
	case DIRECTION_CENTER: {
		if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y))
		{
			pos_.y = cell->GetPos().y - cell->GetSize().y / 2 - size_.y / 2;
			oldInteractCell_[direction] = cell;
		}
		break;
	}
	default:
		break;
	}
}

//プラスブロック処理
void Player::PoleBlockInteract(Cell* cell, DIRECTION direction)
{
	//とりあえず通常ブロックと同じ当たり判定
	BlockInteract(cell, direction);
	oldInteractCell_[direction] = cell;
	//スピード変更
	D3DXVECTOR2 dist = cell->GetPos() - pos_;
	switch (direction) {
	case DIRECTION_DOWN: {
		//同極
		if (pole_ == cell->GetPole()) {
			vel_.y -= BLOCK_ACCELY * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
			gravState_ = GRAV_HALF;
		}
		//異極
		else if (pole_ != cell->GetPole() && pole_ != POLE_NONE) {
			vel_.y += BLOCK_ACCELY * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
		}
		break;
	}
	case DIRECTION_UP: {
		//同極
		if (pole_ == cell->GetPole()) {
			vel_.y += BLOCK_ACCELY * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
		}
		//異極
		else if (pole_ != cell->GetPole() && pole_ != POLE_NONE) {
			vel_.y -= BLOCK_ACCELY * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
			gravState_ = GRAV_HALF;
		}
		break;
	}
	case DIRECTION_LEFT: {
		//同極
		if (pole_ == cell->GetPole()) {
			vel_.x += BLOCK_ACCELX * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
		}
		//異極
		else if (pole_ != cell->GetPole() && pole_ != POLE_NONE) {
			vel_.x -= BLOCK_ACCELX * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
			gravState_ = GRAV_HALF;
		}
	}
	case DIRECTION_RIGHT: {
		//同極
		if (pole_ == cell->GetPole()) {
			vel_.x -= BLOCK_ACCELX * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
		}
		//異極
		else if (pole_ != cell->GetPole() && pole_ != POLE_NONE) {
			vel_.x += BLOCK_ACCELX * (1 / (D3DXVec2Length(&dist) / CELL_SIZE));
			gravState_ = GRAV_HALF;
		}
		break;
	}
	case DIRECTION_CENTER: {
		break;
	}
	default:
		break;
	}
}

void Player::SpikeInteract(Cell* cell, DIRECTION direction) {
	if (CheckHitBB(pos_.x, pos_.y, size_.x, size_.y, cell->GetPos().x, cell->GetPos().y, cell->GetSize().x, cell->GetSize().y) && !isInvincible_)
	{
		Cell** find = std::find(std::begin(oldInteractCell_), std::end(oldInteractCell_), cell);
		if (find == std::end(oldInteractCell_)) // not interacted before
		{
			DecreaseLife();
			isInvincible_ = true;
			oldInteractCell_[direction] = cell;
		}
	}
}