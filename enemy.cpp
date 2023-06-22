/*==============================================================================

   �G�l�~�[�Ǘ� [enemy.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include "enemy.h"
#include "sprite.h"
#include "texture.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

#define ANIME_PTN_YOKO 1
#define ANIME_PTN_TATE 1
#define ANIME_PTN_WAIT 5


#define ANIME_PTN (ANIME_PTN_YOKO * ANIME_PTN_TATE)
#define ANIME_PTN_U (1.0f / ANIME_PTN_YOKO)
#define ANIME_PTN_V (1.0f / ANIME_PTN_TATE)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
struct ENEMY_T{
	D3DXVECTOR2		pos;	//�ʒu�x�N�g��
	D3DXVECTOR2		vel;	//���x�x�N�g��
	D3DXCOLOR		color;	//���_�J���[
	float			rot;
	bool destroyed;
};

static ENEMY_T g_Enemy[NUM_ENEMY];

static int g_TexNo = 0;
static float g_U = 0.0f;
static float g_V = 0.0f;
static int g_AnimePattern = 0;
static int g_AnimeSkipFrame = 0;


//=============================================================================
// ����������
//=============================================================================
void InitEnemy(void)
{
	//�e�N�X�`���̓ǂݍ���
	g_TexNo = LoadTexture((char*)"data/TEXTURE/enemy00.png");

	//������
	for (int i = 0; i < NUM_ENEMY; i++) {
		g_Enemy[i].pos.x = 560 + 200 * i;
		g_Enemy[i].pos.y = 200;
		g_Enemy[i].vel.x = 0.0f;
		g_Enemy[i].vel.y = 0.0f;
		g_Enemy[i].color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		g_Enemy[i].rot = 0.0f;
	}
	
}

//=============================================================================
// �I������
//=============================================================================
void UninitEnemy(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateEnemy(void)
{


	g_AnimeSkipFrame++;
	if (g_AnimeSkipFrame > ANIME_PTN_WAIT)
	{
		g_AnimeSkipFrame = 0;

		g_AnimePattern++;
		if (g_AnimePattern >= ANIME_PTN)
		{
			g_AnimePattern = 0;
		}
	}
	g_U = (g_AnimePattern % ANIME_PTN_YOKO) * ANIME_PTN_U;
//	g_V = (g_AnimePattern / ANIME_PTN_YOKO) * ANIME_PTN_V;
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawEnemy(void)
{
	//�G�l�~�[�̕`��
	for (int i = 0; i < NUM_ENEMY; i++) {
		if (!g_Enemy[i].destroyed) {
			DrawSpriteColorRotate(g_TexNo,
				g_Enemy[i].pos.x, g_Enemy[i].pos.y,
				96.0f, 96.0f,
				g_U, g_V,//UV�l�̎n�_
				ANIME_PTN_U, 1.0f,
				g_Enemy[i].color.r, g_Enemy[i].color.g, g_Enemy[i].color.b, g_Enemy[i].color.a,
				g_Enemy[i].rot);
		}	
	}
}


D3DXVECTOR2 GetEnemyPos(int nIdx) {
	return g_Enemy[nIdx].pos;
}

void DestroyEnemy(int nIdx) {
	g_Enemy[nIdx].destroyed = true;
}

bool GetEnemyState(int nIdx) {
	return g_Enemy[nIdx].destroyed;
}

