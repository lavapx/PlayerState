#include "PlayerState.h"

USING_NS_CC;

Idle PlayerState::idling;
WalkLeft PlayerState::goingLeft;
WalkRight PlayerState::goingRight;
Jump PlayerState::jumping;
Fall PlayerState::falling;

void Idle::handleInput(Player* player, Input input)
{
	switch (input)
	{
	case JUMP_PRESS:
		player->setState(&PlayerState::jumping);
		break;
	case JUMP_RELEASE:
		break;
	case LEFT_PRESS:
		player->setState(&PlayerState::goingLeft);
		break;
	case LEFT_RELEASE:
		break;
	case RIGHT_PRESS:
		player->setState(&PlayerState::goingRight);
		break;
	case RIGHT_RELEASE:
		break;
	default:
		break;
	}
}

void Idle::handleUpdate(Player* player, float dt)
{

}

void WalkLeft::handleInput(Player* player, Input input)
{
	switch (input)
	{
	case JUMP_PRESS:
		player->setState(&PlayerState::jumping);
		break;
	case JUMP_RELEASE:
		break;
	case LEFT_PRESS:
		break;
	case LEFT_RELEASE:
		player->setState(&PlayerState::idling);
		break;
	case RIGHT_PRESS:
		break;
	case RIGHT_RELEASE:
		break;
	default:
		break;
	}
}

void WalkLeft::handleUpdate(Player* player, float dt)
{
	static float maxLeft = 0;
	float currentX = player->getPositionX();
	float newX = currentX - 3;

	if (newX >= maxLeft)
		player->setPositionX(newX);
	else
		player->setPositionX(maxLeft);
}

void WalkRight::handleInput(Player* player, Input input)
{
	switch (input)
	{
	case JUMP_PRESS:
		player->setState(&PlayerState::jumping);
		break;
	case JUMP_RELEASE:
		break;
	case LEFT_PRESS:
		break;
	case LEFT_RELEASE:
		break;
	case RIGHT_PRESS:
		break;
	case RIGHT_RELEASE:
		player->setState(&PlayerState::idling);
		break;
	default:
		break;
	}

}

void WalkRight::handleUpdate(Player* player, float dt)
{
	static float maxRight = Director::getInstance()->getVisibleSize().width - player->getContentSize().width;
	float currentX = player->getPositionX();
	float newX = currentX + 3;

	if (newX <= maxRight)
		player->setPositionX(newX);
	else
		player->setPositionX(maxRight);
}

void Jump::handleInput(Player* player, Input input)
{

}

void Jump::handleUpdate(Player* player, float dt)
{
	static const float jumpStart = player->getPositionY();
	static const float jumpMax = jumpStart + (player->getContentSize().height * 1.8);
	float currentY = player->getPositionY();
	float newY = currentY + 4;

	if (newY <= jumpMax)
		player->setPositionY(newY);
	else
		player->setState(&PlayerState::falling);
}

void Fall::handleInput(Player* player, Input input)
{

}

void Fall::handleUpdate(Player* player, float dt)
{
	static const float jumpMax = player->getPositionY();
	static const float jumpStart = jumpMax - (player->getContentSize().height * 1.8);
	float currentY = player->getPositionY();
	float newY = currentY - 4;

	if (newY >= jumpStart)
		player->setPositionY(newY);
	else
		player->setState(&PlayerState::idling);
}


