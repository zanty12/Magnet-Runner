/*==============================================================================

   �v���C���[�Ǘ� [player.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "player.h"
#include "input.h"
#include "sprite.h"
#include "texture.h"
#include "bullet.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

#define ANIME_PTN_YOKO 3
#define ANIME_PTN_TATE 1
#define ANIME_PTN_WAIT 5

#define ANIME_PTN (ANIME_PTN_YOKO * ANIME_PTN_TATE)
#define ANIME_PTN_U (1.0f / ANIME_PTN_YOKO)
#define ANIME_PTN_V (1.0f / ANIME_PTN_TATE)
#define RPS 3 //1�b�ԉ������Ă�

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************

//=============================================================================
// ����������
//=============================================================================
Player::Player() {
	TexNo = LoadTexture((char*)"data/TEXTURE/majo.png");
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel)
{
	pos = pos;
	vel = vel;
	TexNo = LoadTexture((char*)"data/TEXTURE/majo.png");
}

Player::Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot)
{
	pos = pos;
	vel = vel;
	color = color;
	rot = rot;
	TexNo = LoadTexture((char*)"data/TEXTURE/majo.png");
}

//=============================================================================
// �I������
//=============================================================================
Player::~Player() = default;


//=============================================================================
// �X�V����
//=============================================================================
void Player::UpdatePlayer(void)
{
	static bool isAnim = false;
	static int input = 4;
	//�L�[�{�[�h
	if (GetKeyboardPress(DIK_W))
	{
		Vel_.y = -5.0f;
		isAnim = true;
		V_ = 0.75f;
		input--;
	}
	if (GetKeyboardPress(DIK_S))
	{
		Vel_.y = 5.0f;
		isAnim = true;
		V_ = 0.0f;
		input--;
	}
	if (GetKeyboardPress(DIK_A))
	{
		Vel_.x = -5.0f;
		isAnim = true;
		V_ = 0.25f;
		input--;
	}
	if (GetKeyboardPress(DIK_D))
	{
		Vel_.x = 5.0f;
		isAnim = true;
		V_ = 0.5f;
		input--;
	}

	if ((Vel_.y != 0.0f && Vel_.x < 0.0f) || Vel_.x < 0.0f)
		Rot_ = atan(Vel_.y / Vel_.x) - D3DX_PI;
	else if(Vel_.x != 0.0f || Vel_.y != 0.0f)
		Rot_ = atan(Vel_.y / Vel_.x);

	if (input == 4) {
		Vel_.x = 0.0f;
		Vel_.y = 0.0f;
	}

	Pos_.x += Vel_.x;
	Pos_.y += Vel_.y;

	static int round = 0;
	if (GetKeyboardPress(DIK_SPACE))
	{
		if (round >= 60 / RPS)
		{
			round = 0;
			CreateBullet(Pos_, D3DXVECTOR2(4.0f * cos(Rot_), 4.0f * sin(Rot_)), Rot_ + 0.5f * D3DX_PI);
		}	
	}
	round++;

	//�Q�[���p�b�h
	if (IsButtonPressed(0, BUTTON_A) || GetKeyboardPress(DIK_TAB))
	{
		//���W�̃��Z�b�g
		Pos_.x = SCREEN_WIDTH / 2;
		Pos_.y = SCREEN_HEIGHT / 2;
	}

	if (isAnim == true) {
		AnimeSkipFrame_++;
		if (AnimeSkipFrame_ > ANIME_PTN_WAIT)
		{
			AnimeSkipFrame_ = 0;

			AnimePattern_++;
			if (AnimePattern_ >= ANIME_PTN)
			{
				AnimePattern_ = 0;
			}
		}
	}
	else {
		AnimePattern_ = 1;
		input = 4;
	}
	isAnim = false;
	U_ = (AnimePattern_ % ANIME_PTN_YOKO) * ANIME_PTN_U;
//	V_ = (AnimePattern_ / ANIME_PTN_YOKO) * ANIME_PTN_V;
}

//=============================================================================
// �`�揈��
//=============================================================================
void Player::DrawPlayer(void)
{
	//�v���C���[�̕`��
		DrawSpriteColor(TexNo,
		Pos_.x, Pos_.y,
		96.0f, 96.0f,
		U_, V_,//UV�l�̎n�_
		ANIME_PTN_U, 0.25f,
		Color_.r, Color_.g, Color_.b, Color_.a);
}

D3DXVECTOR2 Player::GetPos(void)
{
	return Pos_;
}


