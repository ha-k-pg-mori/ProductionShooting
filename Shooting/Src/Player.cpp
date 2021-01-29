#include "Player.h"
#include "InputManager.h"
#include "Definition.h"
#include "../Src/Manager/BulletManager.h"

Player::Player()
{
	Player::Pos = Vec2(100.0f, 200.0f);

	Player::Speed = 2.0f;

	Player::AnimationFrameCounter = 0;
	Player::AnimationId = 0;

	Player::Direction = 0;

	Robot = LoadGraph("image/Robot_idle 1.PNG");
}

Player::~Player()
{
	
}

void Player::Init(Vec2 init_pos)
{
	Pos = init_pos;
}

void Player::Update()
{
	
	BulletManager* p_BulletManager = BulletManager::GetInstance();
	InputManager* pInputMng = InputManager::GetInstance();

    if (pInputMng->IsOn(KeyType_Up))
	{
		Pos.Y -= Speed;
	}
    if (pInputMng->IsOn(KeyType_Down))
	{
		Pos.Y += Speed;
	}
	if (pInputMng->IsOn(KeyType_Left))
	{
		Pos.X -= Speed;
	}
	if (pInputMng->IsOn(KeyType_Right))
	{
		Pos.X += Speed;
	}
	if (pInputMng->IsPush(KeyType_Shoot))
	{
		p_BulletManager->CreateBullet(Vec2(Pos.X + 35.0f, Pos.Y + 28.0f));
	}

	if (Pos.X < 0.0f)
	{
		Pos.X = 0.0f;
	}
	if (Pos.Y < 0.0f)
	{
		Pos.Y = 0.0f;
	}
	if (Pos.X > 600.0f)
	{
		Pos.X = 600.0f;
	}
	if (Pos.Y > 420.0f)
	{
		Pos.Y = 420.0f;
	}

	if (AnimationFrameCounter % 4 == 0)
	{
		AnimationFrameCounter = 0;
		AnimationId++;

		if (AnimationId % 3 == 0)
		{
			AnimationId = 0;
		}
	}
}

void Player::Draw()
{

	//DrawGraph(Pos.X, Pos.Y, Robot, FALSE);
	
	int MosyonList[]
	{
		LoadGraph("image/Robot_idle 1.PNG"),
		LoadGraph("image/Robot_idle 2.PNG"),
		LoadGraph("image/Robot_idle 3.PNG"),
	};

	DrawGraph(Pos.X, Pos.Y, MosyonList[AnimationId] , TRUE);
}

Player* Player::m_pInstance = nullptr;

// ���̂���֐�
void Player::CreateInstance()
{

	// null�`�F�b�N����邱�ƂŁA�Q��ڈȍ~�͍���Ȃ�
	if (m_pInstance == nullptr)
	{
		m_pInstance = new Player();
	}
}
// ���̂�j������֐�
void Player::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}
// ���̂����邩��m�F����֐�
bool Player::IsNull()
{
	return (m_pInstance == nullptr);
}
// ���̂�擾����֐�
Player* Player::GetInstance()
{
	return m_pInstance;
}