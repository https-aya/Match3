#include "GameOverScene.h"
#include "DxLib.h"
#include "SceneManager.h"

/***********************
*変数宣言
************************/
int GameOverImage;
int GameOverSE;
int GameOverFlag;

/***********************
*プロトタイプ宣言
************************/

/***********************
*ゲームクリア画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報
************************/
int GameOverScene_Initialize(void)
{
	int ret = 0;

	//画像読込み
	GameOverImage = LoadGraph("images/gameover.png");
	//音源読込み
	GameOverSE = LoadSoundMem("sound/gameover_se.mp3");
	GameOverFlag = FALSE;

	//エラーチェック
	if (GameOverImage == D_ERROR)			//-1をD_ERRORに変更×4
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
*ゲームクリア画面：更新処理
* 引　数：なし
* 戻り値：なし
************************/
void GameOverScene_Update(void)
{
	//ゲームオーバー効果音再生チェック
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
*ゲームクリア画面：描画処理
* 引　数：なし
* 戻り値：なし
************************/
void GameOverScene_Draw(void)
{
	//ゲームオーバー画像表示
	DrawGraph(0, 0, GameOverImage, FALSE);
}