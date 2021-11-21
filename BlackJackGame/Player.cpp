#include "Player.h"
#include "Card.h"

#include<iostream>
#include<vector>


Player::Player() {}
Player::~Player() {}
Player::Player(std::string t)
: playerType(t){}

void Player::setCardInHand(Card c) {cardsInHand.push_back(c);}
std::vector<Card> Player::getCardsInHand() { return cardsInHand; }

void Player::setPlayerType(std::string t) { playerType = t; }
std::string Player::getPlayerType() { return playerType; }

int Player::sumCardsInHand() {
	int sumOfValuesInHand = 0;

	for (auto c : cardsInHand) {
		if (c.getValue() > 11)
		{
			sumOfValuesInHand += 10;
		}
		else {
			sumOfValuesInHand += c.getValue();
		}
	}

	return sumOfValuesInHand;
}
