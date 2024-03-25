#pragma once
#include "Common.h"
#include "Deck.h"
#include "Stack.h"
#include "Card.h"

class Player
{
protected:
	std::vector<Card> m_cards{};
	int m_eights{};
public:
	int draw_count{ 0 };

	void firstDeal(Deck& deck);

	void drawCard(Deck& deck);

	bool checkAvailability(Stack& stack);

	bool hasSameRank(Stack& stack);

	// check if the played card the same as the one in the stack (any rank/suit)
	bool compareStack(Stack& stack, std::size_t i);

	// check if played card is of same rank as previous one
	bool compareSameRank(Stack& stack, std::size_t i);

	virtual void playEight(Stack& stack);

	void printSameRank(Stack& stack);

	// void inputCard for accepting inputs
	/*
	void inputCard(Stack& stack, std::size_t& index,
		std::function<bool(Stack&, std::size_t)> compareCard)
	{
		std::string input{};
		bool wrong_card{ true };

		while (true)
		{
			std::cout << "Choose your card (type it): ";
			std::cin >> input;
			// capitalize the string
			std::transform(input.begin(), input.end(), input.begin(),
				[](unsigned char c) { return std::toupper(c); }
			);

			for (std::size_t i = 0; i < m_cards.size(); i++)
			{
				if (m_cards[i].getCard() == input && compareCard(stack, index))
				{
					index = i;
					wrong_card = false;
					return;
				}
			}

			if (!wrong_card)
			{
				return;
			}
			else
			{
				std::cout << "wrong card";
			}
		}
	}
	*/


	// function to ask player to play or draw card (abandoned)
	/*bool drawOption()
	{
		while (true)
		{
			std::cout << "Play card or draw card?\nAnswer (P/D): ";
			char x{};
			std::cin >> x;
			x = static_cast<char>(std::toupper(
				static_cast<unsigned char>(x)));

			switch (x)
			{
			case 'P':
				return false;
			case 'D':
				return true;
			default:
				std::cout << "P or D only\n";
			}
		}
	}*/


	virtual void playCard(Stack& stack);

	bool hasSameRankPlayer();

	int cardCount();

	Card checkDraw();

	bool drawInput();

	friend std::ostream& operator<<(std::ostream& out, Player& player);


};

