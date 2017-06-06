#include "Player.h"
#include <typeinfo>


Player* Player::create(const std::string& filename)
{
	Player *player = new (std::nothrow) Player();
	if (player && player->initWithFile(filename))
	{
		player->autorelease();
		//default state
		player->setState(&PlayerState::idling);
		return player;
	}
	CC_SAFE_DELETE(player);
	return nullptr;
}

void Player::setState(PlayerState* state)
{
	_state = state;
	CCLOG("New State %s", getStateName());
}

const PlayerState* Player::getState() const
{
	return _state;
}

const char* Player::getStateName() const
{
	return typeid(*_state).name();
}

void Player::input(Input input)
{
	_state->handleInput(this, input);
}

void Player::update(float dt)
{
	_state->handleUpdate(this, dt);
}