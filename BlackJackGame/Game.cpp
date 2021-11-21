#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <vector>
#include <string>

Game::Game() {};
Game::~Game() {};

void Game::playGame() {
	Player dealer("dealer");
	Player regularPlayer("player");

	Deck d(6);
	
	std::cout << "Wellcome to BlackJack game." << std::endl;

	dealer.setCardInHand(d.drawCard());
	regularPlayer.setCardInHand(d.drawCard());
	dealer.setCardInHand(d.drawCard());
	regularPlayer.setCardInHand(d.drawCard());

	firstShowCards(dealer);
	firstShowCards(regularPlayer);
	
	bool playerResponse = askPlayerForCard(regularPlayer);

	while (playerResponse && regularPlayer.sumCardsInHand()<21) {
		regularPlayer.setCardInHand(d.drawCard());
		firstShowCards(regularPlayer);
		checkSumCardsInHand(regularPlayer);
		
		playerResponse = askPlayerForCard(regularPlayer);
	}
}

void Game::firstShowCards(Player p) {

	if (p.getPlayerType() == "player") {
		std::cout << p.getPlayerType() << " hand:" << std::endl;
		for (auto c : p.getCardsInHand()) {
			c.displayCard();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "Dealer hand:" << std::endl;
		std::cout << "XX XX" << "  ";
		std::cout << std::endl;
		p.getCardsInHand()[1].displayCard();
		std::cout << std::endl << std::endl;
	}
}

void Game::displayCards(Player p){
	std::cout << p.getPlayerType() <<  " hand:" << std::endl;
	for (auto c : p.getCardsInHand()) {
		c.displayCard();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Game::askPlayerForCard(Player p) {
	std::cout << std::endl;
	std::cout << "Your hand sum: " << p.sumCardsInHand() << std::endl;
	std::cout << "Do you want one more card?" << std::endl;
	std::cout << "1. Hit" << std::endl;
	std::cout << "2. Stand" << std::endl;
	std::cout << "Your response: ";
	int playerResponse;
	std::cin >> playerResponse;
	std::cout << std::endl;

	if (playerResponse == 1){
		return true;
	}
	else if (playerResponse == 2) {
		return false;
	}
}

void Game::checkSumCardsInHand(Player p) {
	if (p.sumCardsInHand() > 21) {
		std::cout << "Sry bro, sum is over 21!";
	}
	else if (p.sumCardsInHand() < 21) {
		std::cout << "Less then 21!";
	}
	else if (p.sumCardsInHand() == 21 && p.getCardsInHand().size() == 2) {
		std::cout << "Congrats! Blackjack!";
	}
	else if (p.sumCardsInHand() == 21 && p.getCardsInHand().size() > 2) {
		std::cout << "21! but not Blackjack!";
	}
}