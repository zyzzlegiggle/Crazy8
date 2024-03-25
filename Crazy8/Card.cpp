#include "Card.h"

Card::Card(int ranked, int suited)
	: rank{ allRanks[static_cast<std::size_t>(ranked)] }
	, suit{ allSuits[static_cast<std::size_t>(suited)] }
{

}

std::string Card::getCard() const
{
	std::string card_name{};
	static constexpr std::array<char, max_ranks> rank_name{ 'A', '2', '3', '4', '5', '6', '7',
		'8', '9', 'T', 'J', 'Q', 'K' };
	static constexpr std::array<char, max_suits> suit_name{ 'S', 'D', 'H', 'C' };

	card_name += rank_name[rank];
	card_name += suit_name[suit];
	return card_name;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{

	out << card.getCard();
	return out;
}

bool operator== (const Card& c1, const Card& c2)
{
	return (c1.rank == c2.rank && c1.suit == c2.suit);
}