#pragma once
#include <string>

class Card
{
public:
	Card();
	~Card();
	Card(int, int);

	int getValue();
	std::string getSuite();

	void setValue(int v);
	void setSuite(int s);

	void displayCard();
	
private:
	int value;
	int suite;

};

