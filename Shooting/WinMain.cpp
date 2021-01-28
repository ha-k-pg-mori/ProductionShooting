#include "DxLib/DxLib.h"
#include "Src/Manager/SceneManager.h"
#include "Src/Manager/GameManager.h"
#include "Src/Manager/InputManager.h"
#include "Src/Player.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�C���h�E���[�h�ɕύX
	SetOutApplicationLogValidFlag(FALSE);  
	ChangeWindowMode(TRUE);                
	SetGraphMode(640, 480, 32);

	SetMainWindowText("Shooting");
	
	if (DxLib_Init() == -1)  
	{
		return -1;   
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	Player::CreateInstance();

	while (true)
	{
		
		if (ProcessMessage() != 0) { break; }

		
		ClearDrawScreen();
		clsDx();

		

		InputManager* pInputMng = InputManager::GetInstance();
		SceneManager* pSceneMng = SceneManager::GetInstance();
		


		pInputMng->Update();
		pSceneMng->Exec();
		

		pSceneMng->Draw();
		
		
		
		ScreenFlip();
	}

	InputManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();
	
	
		
	DrawLine(0, 0, 960, 540, GetColor(255, 0, 0));

	WaitKey();    

	DxLib_End();    

	return 0;   
	
}