#include "Deck.h"
#include "Card.h"

#include<iostream>
#include<list>
#include <random>
#include <algorithm>
#include <chrono> 

Deck::Deck() {}
Deck::~Deck() {}

Deck::Deck(int numberOfDecks) {
	std::list<int> cardValues = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	std::list<int> cardSuites = { 1, 2, 3, 4 };

	for (int i = 0; i < numberOfDecks; i++) {
		for (auto s : cardSuites) {
			for (auto v : cardValues) {
				cardsInDeck.push_back(Card(v, s));
			}
		}
	}
	shuffleDeck();
}

Card Deck::drawCard() {
	if (!(cardsInDeck.empty())) {
		Card drawnCard = cardsInDeck.back();
		cardsInDeck.pop_back();

		return drawnCard;
	}
	else {
		std::cout << "Deck out of cards";
		exit(1);
	}
}


void Deck::shuffleDeck() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	shuffle(cardsInDeck.begin(), cardsInDeck.end(), e);
}

void Deck::numberOfCardsInDeck() {
	std::cout << "U deku je karata: " << cardsInDeck.size();
}
