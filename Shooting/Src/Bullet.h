#ifndef BULLET_H
#define BULLET_H

#include "Common/Vec.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Init(Vec2 init_pos); 
	virtual void Update();
	virtual void Draw();

	static void CreateInstance();

	static void DestroyInstance();

	static bool IsNull();

	static Bullet* GetInstance();

	bool IsActive;

private:
	Vec2 Pos;
	float Speed;
	
	

private:
	static Bullet* m_pInstance;
};

#endif // 



