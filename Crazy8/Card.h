#pragma once
#include "Common.h"

class Card
{
public:
	enum Rank
	{
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks
	};

	enum Suit
	{
		suit_spade,
		suit_diamond,
		suit_heart,
		suit_clover,

		max_suits
	};

	static constexpr std::array<Rank, max_ranks> allRanks{ rank_ace, rank_2, rank_3,
															rank_4, rank_5, rank_6, rank_7,
															rank_8, rank_9, rank_10,
															rank_jack, rank_queen, rank_king };
	static constexpr std::array<Suit, max_suits> allSuits{ suit_spade, suit_diamond,
															suit_heart, suit_clover, };


	Rank rank{};
	Suit suit{};

	Card() = default;
	Card(int ranked, int suited);

	std::string getCard() const;

	friend std::ostream& operator<<(std::ostream& out, const Card& card);

	friend bool operator== (const Card& c1, const Card& c2);

};

