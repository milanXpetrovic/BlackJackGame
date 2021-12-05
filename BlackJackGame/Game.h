#pragma once

#include "Card.h"
#include "Player.h"

#include <vector>
#include <string>

class Game
{
public:
	Game();
	~Game();

	void playGame();
	void firstShowCards(Player);
	void displayCards(Player);
	bool askPlayerForCard(Player);
	void checkSumCardsInHand(Player);
	void checkWhoWon(int dealerHand, int playerHand);
private:
	
};

