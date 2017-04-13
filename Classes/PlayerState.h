#ifndef __PLAYER_STATE_H__
#define __PLAYER_STATE_H__

#include "cocos2d.h"
#include "Player.h"
#include "enums.h"


class Player;
class Idle;
class WalkLeft;
class WalkRight;
class Jump;
class Fall;

class PlayerState
{
public:

	static Idle idling;
	static WalkLeft goingLeft;
	static WalkRight goingRight;
	static Jump jumping;
	static Fall falling;

	virtual void handleInput(Player* player, Input input) = 0;
	virtual void handleUpdate(Player* player, float dt) = 0;
};

class Idle : public PlayerState
{
public:

	void handleInput(Player* player, Input input);
	void handleUpdate(Player* player, float dt);
};

class WalkLeft : public PlayerState
{
public:

	void handleInput(Player* player, Input input);
	void handleUpdate(Player* player, float dt);
};

class WalkRight : public PlayerState
{
public:

	void handleInput(Player* player, Input input);
	void handleUpdate(Player* player, float dt);
};

class Jump : public PlayerState
{
public:

	void handleInput(Player* player, Input input);
	void handleUpdate(Player* player, float dt);
};

class Fall : public PlayerState
{
public:

	void handleInput(Player* player, Input input);
	void handleUpdate(Player* player, float dt);
};

#endif // __PLAYER_STATE_H__