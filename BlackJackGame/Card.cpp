#include "Card.h"
#include<iostream>

using namespace std;

Card::Card() {};
Card::~Card() {}

Card::Card(int v, int s)
: value(v), suite(s)
{}

void Card::setValue(int v) { value = v; }
void Card::setSuite(int s) { suite = s; }

int Card::getValue() { return value; }

std::string Card::getSuite() { 
	if (suite == 1) {
		return "<>";
	}
	else if (suite == 2) {
		return "<3";
	}
	else if (suite == 3) {
		return "-3";
	}
	else {
		return "->"; }
	}

void Card::displayCard() {
	std::cout << getValue() << " " << getSuite();
}

