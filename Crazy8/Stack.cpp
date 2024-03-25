#include "Stack.h"

void Stack::firstDeal(Deck& deck)
{
	m_current = deck.deal();
}

void Stack::updateCurrent(Card& card)
{
	m_current = card;
}

void Stack::getCurrent()
{
	std::cout << m_current;
}

Card& Stack::returnCurrent()
{
	return m_current;
}
