#include "Bullet.h"
#include "InputManager.h"

Bullet::Bullet()
{
	Bullet::Pos = Vec2(0, 0);

	Bullet::Speed = 10.0f;

	IsActive = false;
}

Bullet::~Bullet()
{
	
}

void Bullet::Init(Vec2 init_pos)
{
	Pos = init_pos;
}

void Bullet::Update()
{
	Pos.X += Speed;
	if (Pos.X > 640.0f)
	{
		IsActive = false;
	}
}

void Bullet::Draw()
{
	LoadGraphScreen(Pos.X, Pos.Y, "image/Bullet1.png", TRUE);
}

Bullet* Bullet::m_pInstance = nullptr;

// ���̂���֐�
void Bullet::CreateInstance()
{
	// null�`�F�b�N����邱�ƂŁA�Q��ڈȍ~�͍���Ȃ�
	if (m_pInstance == nullptr)
	{
		m_pInstance = new Bullet();
	}
}
// ���̂�j������֐�
void Bullet::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}
// ���̂����邩��m�F����֐�
bool Bullet::IsNull()
{
	return (m_pInstance == nullptr);
}
// ���̂�擾����֐�
Bullet* Bullet::GetInstance()
{
	return m_pInstance;
}