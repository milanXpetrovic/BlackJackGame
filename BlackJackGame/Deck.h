#pragma once

#include<iostream>
#include<vector>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();
	Deck(int);

	Card drawCard();
	void shuffleDeck();
	void numberOfCardsInDeck();

	void dealCardsToPlayers();


private:
	std::vector<Card> cardsInDeck;
};

