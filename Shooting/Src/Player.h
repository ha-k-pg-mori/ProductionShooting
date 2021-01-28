#ifndef PLAYER_H
#define PLAYER_H

#include "Common/Vec.h"

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

private:
	Vec2 Pos;

};

#endif // !PLAYER_H

