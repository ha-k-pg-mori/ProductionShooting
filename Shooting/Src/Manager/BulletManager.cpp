#include "BulletManager.h"

BulletManager::BulletManager()
{
	for (int i = 0; i < 1000; i++)
	{
		Bullets[i].Init(Vec2(0.0f, 0.0f));
	}
}

BulletManager::~BulletManager()
{

}
	
void BulletManager::Update()
{
	for (int i = 0; i < 1000; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			continue;
		}

		Bullets[i].Update();
	}
}

void BulletManager::Draw()
{
	for (int i = 0; i < 1000; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			continue;
		}
		Bullets[i].Draw();
	}
}

Bullet* BulletManager::CreateBullet(Vec2 init_pos)
{
	for (int i = 0; i < 1000; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			Bullets[i].Init(init_pos);
			Bullets[i].IsActive = true;

			return &Bullets[i];
		}
	}

	return nullptr;
}

Bullet* BulletManager::GetBullet(int index)
{
	if(index < 0 || index >= 1000)
	{
		return nullptr;
	}

	if (Bullets[index].IsActive == false)
	{
		return nullptr;
	}
	return &Bullets[index];
}

BulletManager* BulletManager::m_pInstance = nullptr;

// ���̂���֐�
void BulletManager::CreateInstance()
{

	// null�`�F�b�N����邱�ƂŁA�Q��ڈȍ~�͍���Ȃ�
	if (m_pInstance == nullptr)
	{
		m_pInstance = new BulletManager();
	}
}
// ���̂�j������֐�
void BulletManager::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}
// ���̂����邩��m�F����֐�
bool BulletManager::IsNull()
{
	return (m_pInstance == nullptr);
}
// ���̂�擾����֐�
BulletManager* BulletManager::GetInstance()
{
	return m_pInstance;
}