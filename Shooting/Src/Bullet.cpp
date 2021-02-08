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

