#ifndef PLAYER_H
#define PLAYER_H

#include "Common/Vec.h"

class Player
{
public:
	Player();
	~Player();
	
	void Init(Vec2 init_pos);

	virtual void Update();
	virtual void Draw();

	//Player* number(int Counter);

	static void CreateInstance();

	static void DestroyInstance();

	static bool IsNull();

	static Player* GetInstance();

	

private:
	Vec2 Pos;
	float Speed;
	
	int AnimationFrameCounter;
	int AnimationId;

	int counter;

	int MousyonList[];

private:
	static Player* m_pInstance;

};

#endif // !PLAYER_H

