#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "../Common/Vec.h"
#include "../Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	virtual void Update();
	virtual void Draw();

	Bullet* CreateBullet(Vec2 init_pos);

	Bullet* GetBullet(int index);

	static void CreateInstance();

	static void DestroyInstance();

	static bool IsNull();

	static BulletManager* GetInstance();

private:
	Bullet Bullets[1000];

private:
	static BulletManager* m_pInstance;
};

#endif // !BULLETMANAGER_H



