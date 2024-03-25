#include "Enemy.h"

void Enemy::playCard(Stack& stack)
{
	for (std::size_t i = 0; i < m_cards.size(); i++)
	{
		if (compareStack(stack, i))
		{
			std::cout << "Enemy played " << m_cards[i] << "!\n";
			stack.updateCurrent(m_cards[i]);
			m_cards.erase(m_cards.begin() + static_cast<int>(i));
			break;
		}
	}

	if (hasSameRank(stack))
	{
		std::cout << "Enemy has a card of the same rank\n";

		for (std::size_t i = 0; i < m_cards.size(); i++)
		{
			if (compareSameRank(stack, i))
			{
				std::cout << "Enemy played " << m_cards[i] << "!\n";
				stack.updateCurrent(m_cards[i]);
				m_cards.erase(m_cards.begin() + static_cast<int>(i));
				break;
			}
		}
	}

	if (stack.returnCurrent().getCard()[0] == '8') // if enemy played 8
	{
		playEight(stack);
	}
	return;
}

void Enemy::playEight(Stack& stack)
{
	std::cout << "Enemy used 8\n";
	int suit_choice{ Random::get(1,4) };

	auto updateStack{
			[&stack, suit_choice]() {
				stack.returnCurrent().suit = Card::allSuits[static_cast<std::size_t>
				(suit_choice - 1)];
			}
	};

	std::cout << "Enemy chose ";
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
	}
}