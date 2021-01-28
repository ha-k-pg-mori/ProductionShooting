#include "DxLib/DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(0.5);
	SetGraphMode(1920, 1080, 32);
	
	if (DxLib_Init() == -1)  // �c�w���C�u��������������
	{
		return -1;   // �G���[���N�����璼���ɏI��
	}

	while (true)
	{
		// Windows�̃��b�Z�[�W�����Ɏ��s�������A�����߂�ꂽ��I��
		if (ProcessMessage() != 0) { break; }

		// DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();


		// DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();
	}
	
		//�������
	DrawLine(0, 0, 960, 540, GetColor(255, 0, 0));

	WaitKey();    // �L�[���͑҂�

	DxLib_End();    // �c�w���C�u�����g�p�̏I������

	return 0;    // �\�t�g�̏I�� 
	
}