#pragma once

#include "Card.h"
#include <vector>
#include <string>

class Player
{
public:
	Player();
	~Player();

	Player(std::string);

	void setCardInHand(Card);
	std::vector<Card> getCardsInHand();

	void setPlayerType(std::string);
	std::string getPlayerType();
	
	int sumCardsInHand();

private:
	std::vector<Card> cardsInHand;
	std::string playerType;
};

