/* Author: Josiah Stadler
   Date: 10/10/20
   Purpose: This is the header file for the deck class. It is used with
			the card class to simulate the creation and use of a deck of cards.
*/
#pragma once
#ifndef DECK_h
#define DECK_H
#include "Card.h"
#include<vector>
#include <stack>

class Deck {

public:
	//Default/ no arg constructor
	Deck();
	//Deconstructor
	~Deck();
	//draws one card off top of deck
	Card* draw();
	//checks if deck is empty
	bool stackEmpty();
	// void makeDeck();
	void printDeck();
	//Shuffles entire deck
	void shuffle();
protected:	
	std::vector<Card*> deck;//vector of pointers for master/fresh deck
	std::stack <Card*> shuffledDeck;//stack of pointers to hold shuffled deck
};
#endif

