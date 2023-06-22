/*==============================================================================

   �v���C���[�Ǘ�[player.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#include "main.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

class Player {
private:
	D3DXVECTOR2		Pos_ = D3DXVECTOR2(960,960);	//�ʒu�x�N�g��
	D3DXVECTOR2		Vel_ = D3DXVECTOR2(0.0f, 0.0f);	//���x�x�N�g��
	D3DXCOLOR		Color_ = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//���_�J���[
	float			Rot_ = 0;
	int TexNo = 0;
	float U_ = 0.0f;
	float V_ = 0.0f;
	int AnimePattern_ = 0;
	int AnimeSkipFrame_ = 0;


public:
	Player();
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel);
	Player(D3DXVECTOR2 pos, D3DXVECTOR2 vel, D3DXCOLOR color, float rot);
	~Player();
	void UpdatePlayer(void);
	void DrawPlayer(void);
	D3DXVECTOR2 GetPos(void);


};


