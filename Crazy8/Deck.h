#pragma once
#include "Card.h"

class Deck
{
private:
	std::array<Card, 52> m_cards{};
	std::size_t m_index{ 0 };
public:
	std::size_t i{ 0 };

	Deck();

	void shuffle();

	Card deal();

	void getDeck();
};