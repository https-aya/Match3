#include "GameOverScene.h"
#include "DxLib.h"
#include "SceneManager.h"

/***********************
*�ϐ��錾
************************/
int GameOverImage;
int GameOverSE;
int GameOverFlag;

/***********************
*�v���g�^�C�v�錾
************************/

/***********************
*�Q�[���N���A��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���
************************/
int GameOverScene_Initialize(void)
{
	int ret = 0;

	//�摜�Ǎ���
	GameOverImage = LoadGraph("images/gameover.png");
	//�����Ǎ���
	GameOverSE = LoadSoundMem("sound/gameover_se.mp3");
	GameOverFlag = FALSE;

	//�G���[�`�F�b�N
	if (GameOverImage == D_ERROR)			//-1��D_ERROR�ɕύX�~4
	{
		ret = D_ERROR;
	}
	if (GameOverSE == D_ERROR)
	{
		ret = D_ERROR;
	}

	return ret;
}

/***********************
*�Q�[���N���A��ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
************************/
void GameOverScene_Update(void)
{
	//�Q�[���I�[�o�[���ʉ��Đ��`�F�b�N
	if (CheckSoundMem(GameOverSE) == 0)
	{
		if (GameOverFlag == TRUE)
		{
			Change_Scene(E_GAME_OVER);
		}
		else
		{
			PlaySoundMem(GameOverSE,DX_PLAYTYPE_BACK);
			GameOverFlag = TRUE;
		}
	}
}

/***********************
*�Q�[���N���A��ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
************************/
void GameOverScene_Draw(void)
{
	//�Q�[���I�[�o�[�摜�\��
	DrawGraph(0, 0, GameOverImage, FALSE);
}