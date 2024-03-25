#pragma once
#include "Card.h"
#include "Deck.h"

class Stack
{
private:
	Card m_current{};
public:
	void firstDeal(Deck& deck);

	void updateCurrent(Card& card);

	void getCurrent();

	Card& returnCurrent();
};
