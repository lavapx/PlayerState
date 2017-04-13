#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "enums.h"
#include "PlayerState.h"

class PlayerState;

class Player : public cocos2d::Sprite
{
	friend class PlayerState;
	friend class Idle;
	friend class WalkLeft;
	friend class WalkRight;
	friend class Jump;
	friend class Fall;

	
public:
	

	static Player* create(const std::string& filename);

	PlayerState* getState();
	const char* getStateName();

	void update(float dt) override;
	void input(Input input);

protected:

	void setState(PlayerState* state);

private:

	PlayerState* _state;

};

#endif // __PLAYER_H__