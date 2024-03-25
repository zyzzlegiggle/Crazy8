#include "Player.h"

void Player::firstDeal(Deck& deck)
{
	for (std::size_t i = 0; i < 5; i++)
	{
		m_cards.push_back(deck.deal());
	}
}

void Player::drawCard(Deck& deck)
{
	m_cards.push_back(deck.deal());
}

bool Player::checkAvailability(Stack& stack)
{
	bool card_available{ false };
	for (std::size_t i = 0; i < m_cards.size(); i++)
	{
		if (m_cards[i].getCard()[0] == stack.returnCurrent()
			.getCard()[0] || m_cards[i].getCard()[1] ==
			stack.returnCurrent().getCard()[1] ||
			m_cards[i].getCard()[0] == '8')
		{
			if (m_cards[i].getCard()[0] == '8')
			{
				m_eights++;
			}
			card_available = true;
		}
	}
	return card_available;
}

bool Player::hasSameRank(Stack& stack)
{
	bool same_rank{ false };
	for (std::size_t i = 0; i < m_cards.size(); i++)
	{
		if (m_cards[i].getCard()[0] == stack.returnCurrent()
			.getCard()[0] && m_cards[i].getCard()[0] != '8')
		{
			same_rank = true;
			break;
		}
	}

	return same_rank;
}

// check if the played card the same as the one in the stack (any rank/suit)
bool Player::compareStack(Stack& stack, std::size_t i)
{
	return (m_cards[i].getCard()[0] == stack.returnCurrent()
		.getCard()[0] || m_cards[i].getCard()[1] ==
		stack.returnCurrent().getCard()[1] ||
		m_cards[i].getCard()[0] == '8');
}

// check if played card is of same rank as previous one
bool Player::compareSameRank(Stack& stack, std::size_t i)
{
	return (m_cards[i].getCard()[0] == stack.returnCurrent()
		.getCard()[0]);
}

void Player::playEight(Stack& stack)
{
	std::cout << "You played 8th card! \n";
	std::cout << "You can choose the next suit\n";
	while (true)
	{
		std::cout << "1. Spades\n2. Diamond\n3. Heart\n4. Clover\n";
		std::cout << "Your choice: ";
		int suit_choice{};
		std::cin >> suit_choice;


		auto updateStack{
			[&stack, suit_choice]() {
				stack.returnCurrent().suit = Card::allSuits[static_cast<std::size_t>
				(suit_choice - 1)];
			}
		};

		std::cout << "Player chose ";
		switch (suit_choice)
		{
		case 1:
			std::cout << "spades\n";
			updateStack();
			return;
		case 2:
			std::cout << "diamond\n";
			updateStack();
			return;
		case 3:
			std::cout << "heart\n";
			updateStack();
			return;
		case 4:
			std::cout << "clover\n";
			updateStack();
			return;
		default:
			std::cout << "Invalid suit\n";
		}
	}
}

void Player::printSameRank(Stack& stack)
{
	std::cout << "Eligible card(s): ";
	for (std::size_t i = 0; i < m_cards.size(); i++)
	{
		if (m_cards[i].getCard()[0] == stack.returnCurrent()
			.getCard()[0])
		{
			std::cout << m_cards[i].getCard() << ' ';
		}
	}
	std::cout << '\n';
}

// void inputCard for accepting inputs (unused)
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


void Player::playCard(Stack& stack)
{
	std::cout << "You can play your card(s) ";
	if (m_eights >= 1)
	{
		std::cout << "and you also have the 8th card(s)\n";
	}
	else
	{
		std::cout << '\n';
	}

	std::size_t index{};
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
			if (m_cards[i].getCard() == input && compareStack(stack, i))
			{
				index = i;
				wrong_card = false;
				break;
			}
		}

		if (wrong_card)
		{
			std::cout << "wrong card\n";
		}
		else
		{
			break;
		}
	}

	// inputCard(stack, index, compareStack); experimental
	stack.updateCurrent(m_cards[index]);
	m_cards.erase(m_cards.begin() + static_cast<int>(index));


	if (hasSameRank(stack))
	{
		if (hasSameRankPlayer())
		{
			wrong_card = true;
			while (true)
			{
				printSameRank(stack);

				std::cout << "Choose your card (type it): ";
				std::cin >> input;
				// capitalize the string
				std::transform(input.begin(), input.end(), input.begin(),
					[](unsigned char c) { return std::toupper(c); }
				);

				for (std::size_t i = 0; i < m_cards.size(); i++)
				{
					// use compareSameRank
					if (m_cards[i].getCard() == input && compareSameRank(stack, i))
					{
						index = i;
						wrong_card = false;
						break;
					}
				}

				if (wrong_card)
				{
					std::cout << "wrong card\n";
				}
				else
				{
					break;
				}

			}

			// inputCard(stack, index, compareSameRank); // experimental (probably unused)
			stack.updateCurrent(m_cards[index]);
			m_cards.erase(m_cards.begin() + static_cast<int>(index));
		}

	}

	if (stack.returnCurrent().getCard()[0] == '8') // if player played 8
	{
		playEight(stack);
	}


	m_eights = 0; // reset eight counts
}

bool Player::hasSameRankPlayer()
{
	char input{};
	while (true)
	{

		std::cout << "You have card of the same rank. Want to play it?\n";
		std::cout << "(Y/N): ";
		std::cin >> input;
		input = static_cast<char>(std::toupper(
			static_cast<unsigned char>(input)));

		switch (input)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		default:
			std::cout << "Y/N only\n";
		}

	}
}

int Player::cardCount()
{
	return static_cast<int>(m_cards.size());
}

Card Player::checkDraw()
{
	Card lastValue = m_cards.back();
	return lastValue;
}

bool Player::drawInput()
{
	while (true)
	{
		std::cout << "You don't have the card. Draw one?( Y / N(give up) )"
			<< "\nAnswer: ";
		char draw_input{};
		std::cin >> draw_input;
		draw_input = static_cast<char>(std::toupper(
			static_cast<unsigned char>(draw_input)));

		switch (draw_input)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		default:
			std::cout << "Please choose between Y / N\n";
		}

	}

}

std::ostream& operator<<(std::ostream& out, Player& player)
{
	for (auto e : player.m_cards)
	{
		out << e << ' ';
	}
	return out;
}
