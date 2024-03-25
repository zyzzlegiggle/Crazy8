#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	void playCard(Stack& stack) override;

	void playEight(Stack& stack) override;
};

