#include "DxLib/DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウインドウモードに変更
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(0.5);
	SetGraphMode(1920, 1080, 32);
	
	if (DxLib_Init() == -1)  // ＤＸライブラリ初期化処理
	{
		return -1;   // エラーが起きたら直ちに終了
	}

	

	//線を引く
	DrawLine(0, 0, 960, 540, GetColor(255, 0, 0));

	WaitKey();    // キー入力待ち

	DxLib_End();    // ＤＸライブラリ使用の終了処理

	return 0;    // ソフトの終了 
}