#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Player.h"
#include "../Manager/BulletManager.h"


Player g_Player;
Vec2 g_PlayerPos = Vec2(100.0f, 200.0f);
BulletManager g_BulletManager;

enum
{
	STEP_START_JINGLE,
	STEP_INPUT,
	STEP_CLEAR_JINGLE,
	STEP_END,
};



InGameScene::InGameScene()
	
{
	Player::CreateInstance();
	BulletManager::CreateInstance();

	

	BG = LoadGraph("image/sky1.png");
}

InGameScene::~InGameScene()
{
	Player::DestroyInstance();
	BulletManager::DestroyInstance();
}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_START_JINGLE: step_StartJingle(); break;
	case STEP_INPUT:  step_Input();  break;
	case STEP_CLEAR_JINGLE:  step_ClearJingle();  break;
	default: break;
	}

	Player* pPlayer = Player::GetInstance();
	BulletManager* p_BulletManager = BulletManager::GetInstance();

	p_BulletManager->Update();

	pPlayer->Update();

	// @@Debug �J�ڊm�F�p�̉�����
	// m_Step��J�E���g�A�b�v
	/*m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Result);
	}*/
	

}

void InGameScene::Draw()
{		
	Player* pPlayer = Player::GetInstance();
	BulletManager* p_BulletManager = BulletManager::GetInstance();

	DrawExtendGraph(0, 0, 100 + 130 * 5, 0 + 480, BG, TRUE);

	p_BulletManager->Draw();
	pPlayer->Draw();



	

	//g_Player.Draw();

	/*int MosyonList[]
	{
		
	};*/
	

	//DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, MosyonList[Animation], FALSE);

	
	/*if (IsClear())
	{
		DrawString(100, 240, "!! Game Clear !!", GetColor(250, 250, 250));
	}*/

	

	DrawString(20, 20, "InGameScene", GetColor(0, 0, 0));

	//DrawFormatString(400, 20, Color, "%d", ClickCounter);
	
}

bool InGameScene::IsEnd() const
{
	// @@Debug �J�ڊm�F�p�̉�����
	return (m_Step == STEP_END);
}

void InGameScene::step_StartJingle()
{
	set_Step(STEP_INPUT);

}

void InGameScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Clear))
	{
		set_Step(STEP_END);
		SceneManager::SetNextScene(SceneID_Result);
	}


	if(IsClear())
	{
		set_Step(STEP_CLEAR_JINGLE);
	}
}

void InGameScene::step_ClearJingle()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		set_Step(STEP_END);
		SceneManager::SetNextScene(SceneID_Result);
	}
}


// �Q�[���N���A����
// true = �N���A���Ă���
// false = ���N���A
bool InGameScene::IsClear() const
{
	
	return true;
}

// ��������ԂɃ��Z�b�g
void InGameScene::Reset()
{
	
}

// �ړ�����
void InGameScene::Move(DirType dir_)
{
	// DirType���͈͓��
	if (dir_ >= DirType_Up && dir_ >= DirType_Max)
	{
		return;
	}

	
			
	
}