#include "Deck.h"

Deck::Deck()
{
	for (auto rank : Card::allRanks)
	{
		for (auto suit : Card::allSuits)
		{
			m_cards[i] = Card{ rank, suit };
			i++;
		}
	}
	shuffle();
}

void Deck::shuffle()
{
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
	m_index = 0;
}

Card Deck::deal()
{
	assert(m_index < 52 && "all cards dealt");
	return m_cards[m_index++];
}

void Deck::getDeck()
{
	for (auto e : m_cards)
	{
		std::cout << e;
	}
}