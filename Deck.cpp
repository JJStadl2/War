#include "Card.h"
#include "Deck.h"
#include <iostream>
#include<random>

/*
 * Name: Josiah Stadler
 * Course: csc-339-01
 * Date: 10/10/20
 * Purpose: This file contains the definitions for the methods of the Deck.h header file
*/
using namespace std;

Deck::Deck() {
	for (int i = Heart; i <= Spade; i++) {
		for (int j = Two; j <= Ace; j++) {
			this->deck.push_back(new Card(cardValues(j), suitValues(i)));
		}
	}	
}
Deck:: ~Deck() {
	for (auto& i : deck) {
		delete i;
	}
}
/*
* Shuffles master deck and copies result into stack to hold shuffled deck.
*/
void Deck::shuffle() {
	unsigned num = 0;

	std::shuffle(deck.begin(), deck.end(), default_random_engine(num));
	if (shuffledDeck.empty()) {

		for (auto& c : deck) {
			shuffledDeck.push(c);
		}
	}
	else {
		while (!shuffledDeck.empty()) {
			shuffledDeck.pop();
		}
		for (auto& c : deck) {
			shuffledDeck.push(c);
		}
	}

}
Card* Deck::draw() {

	//stores/represents top card that is dealt off top of deck
	Card* c = shuffledDeck.top();

	//Shows card being dealt- removed for dealing in War
	//c->printCard();

	//removes dealt card from working deck
	shuffledDeck.pop();
	return c;
}
void Deck::printDeck() {
	// for sequance of output
	int count = 1;

	for (const auto& deck : deck) {
		cout << "======= CARD NUMBER " << count << "==========" << endl;
		deck->printCard();
		count++;
	}
}
bool Deck::stackEmpty() {
	if (deck.size() == 0) {
		return true;
	}
	else false;
}


