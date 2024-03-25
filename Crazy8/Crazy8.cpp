#include "Common.h"
#include "Card.h"
#include "Deck.h"
#include "Stack.h"
#include "Player.h"
#include "Enemy.h"

// this function is experimental(probably unused)
/*
void xTurn(bool& game_play, bool& player_turn, bool& enemy_turn, Player& p, Stack& stack)
{
	if (game_play)
	{
		std::cout << "Choose your card (type it): ";
		std::string input;
		std::cin >> input;
		p.playCard(input, stack);
		std::cout << "current card on top of pile is:";
		stack.getCurrent();
		std::cout << '\n';

		if (p.cardCount() == 0)
		{
			std::cout << "You Win!";
			return 1;
		}

		game_play = p.compareStack(stack);

		if (!game_play)
		{
			enemy_turn = true;
			player_turn = false;
		}
	}
	else
	{
		p.draw_count = 0;
		while (p.draw_count <= draw_max)
		{

			if (drawInput())
			{
				p.drawCard(deck);
				game_play = p.compareStack(stack);

				if (!game_play)
				{
					p.draw_count++;
				}
				else
				{
					break;
				}
			}
			else
			{
				p.draw_count = draw_max;
			}
		}
		if (p.draw_count == draw_max)
		{
			std::cout << "You pass\n";
			player_turn = false;
			enemy_turn = true;
		}
	}
}
*/

enum GameResult
{
	playerWin,
	enemyWin
};


namespace GameSettings
{
	GameResult gameSession()
	{
		Player player{};
		Deck deck{};
		Stack stack{};
		Enemy enemy{};


		player.firstDeal(deck);
		enemy.firstDeal(deck);
		stack.firstDeal(deck);

		bool player_turn{ true };
		bool enemy_turn{ false };
		bool player_play{};
		bool enemy_play{};

		int draw_max{ 3 };

		std::cout << "Let's Play Crazy8!\n";
		std::cout << "Rules:\n1. You and enemy will be given 5 cards"
			<< "\n2. There will be a card on top of stack"
			<< "\n3. For example, if the card on top of stack is 6H, you can play any H, or any 6 (6C, 6S, 6D)"
			<< "\n4. You can play any 8 anytime, if so you can choose a new suit"
			<< "\n5. If you ran out of cards, you can draw max 3 times from deck"
			<< "\n6. If you play a card, you can play another with the same rank"
			<< "\n7. THE FASTEST ONE TO RAN OUT OF CARDS WIN!! HAVE FUN!\n";

		while (true)
		{
			if (player_turn)
			{
				std::cout << "------------------------------------------------------------------------------------------------------------------------" << '\n';
				std::cout << "current card on top of pile is:";
				stack.getCurrent();
				std::cout << '\n';
				std::cout << "enemy has " << enemy.cardCount() << " cards\n";
				std::cout << "Your cards are: " << player << '\n';

				player_play = player.checkAvailability(stack);

				if (player_play) // have cards to play
				{

					player.playCard(stack);

					if (player.cardCount() == 0)
					{
						return playerWin;
					}

					enemy_turn = true;
					player_turn = false;
				}
				else // no cards to play
				{
					player.draw_count = 0;
					while (player.draw_count < draw_max)
					{

						if (player.drawInput())
						{
							player.drawCard(deck);
							std::cout << "Player draw " << player.checkDraw() << '\n';
							player_play = player.checkAvailability(stack);

							if (!player_play)
							{
								player.draw_count++;
							}
							else
							{
								player.playCard(stack);
								player_turn = false;
								enemy_turn = true;
								break;
							}
						}
						else
						{
							std::cout << "You give up!\n";
							return enemyWin;
						}
					}
					if (player.draw_count == draw_max)
					{
						std::cout << "You pass the turn\n";
						player_turn = false;
						enemy_turn = true;
					}
				}
			}



			else if (enemy_turn)
			{
				std::cout << "------------------------------------------------------------------------------------------------------------------------" << '\n';
				std::cout << "current card on top of pile is:";
				stack.getCurrent();
				std::cout << '\n';
				enemy_play = enemy.checkAvailability(stack);
				if (enemy_play)
				{
					enemy.playCard(stack);

					if (enemy.cardCount() == 0)
					{
						return enemyWin;
					}


					enemy_turn = false;
					player_turn = true;

				}
				else
				{
					enemy.draw_count = 0;
					while (enemy.draw_count < draw_max)
					{
						enemy.drawCard(deck);
						std::cout << "Enemy draw a card\n";
						enemy_play = enemy.checkAvailability(stack);

						if (!enemy_play)
						{
							enemy.draw_count++;
						}
						else
						{
							enemy.playCard(stack);
							enemy_turn = false;
							player_turn = true;
							break;
						}
					}
					if (enemy.draw_count == draw_max)
					{
						std::cout << "Enemy pass the turn\n";
						enemy_turn = false;
						player_turn = true;
					}
				}
			}



		}
	}
}

int main()
{
	switch (GameSettings::gameSession())
	{
	case playerWin:
		std::cout << "You Win!";
		break;
	case enemyWin:
		std::cout << "You Lose!";
		break;
	}

	std::cout << "\n\n";

	return 0;
}