#include <iostream>
#include "Card.h"
/*
 * Name: Josiah Stadler
 * Course: csc-339-01
 * Date: 9/26/20
 * Purpose: This file contains the definitions for the methods of the Card.h header file
*/

//Default Constructor
/*
Card::Card() {

	cout << " no info given" << endl;
}
*/


//Constructor 

Card::Card(cardValues m, suitValues s) {
	suit = getSuit(s);
	value = m;
	valueStr = getMagOfCards(m);
}

//Deconstructor
Card:: ~Card() {

}
int Card::  areEqualMags(Card c) {
	if (c.value > this->value) {
	//	std::cout << c.valueStr << " IS GREATER THAN " << this->valueStr << ::endl;
		return 1;
	}
	else if (c.value < this->value) {
		//std::cout << c.valueStr << " IS LESS THAN " << this->valueStr << ::endl;
		return -1;
	}
	else {
		//std::cout << c.valueStr << " IS EQUAL TO " << this->valueStr << ::endl;
		return 0;
	}
}
void Card::areEqualSuits(Card c) {
	if (c.suit.at(0) != this->suit.at(0)) {
		std::cout << c.suit << " IS NOT THE SAME AS " << this->suit << ::endl;
	}
	else {
		std::cout << c.suit << " IS THE SAME AS " << this->suit << ::endl;
	}
}

void Card::printCard() {
	std::cout << this->valueStr << " of " << this->suit << "s" << std::endl;
	//std::cout << "Suit = " << this->suit << std::endl;
	//std::cout << "Value = " << this->valueStr << std::endl;
}
string Card::getSuit(suitValues s) {
	switch (s)
	{
	case suitValues::Diamond:
		return "Diamond";
		break;
	case suitValues::Spade:
		return "Spade";
		break;
	case suitValues::Heart:
		return "Heart";
		break;
	case suitValues::Club:
		return "Club";
		break;
	default:
		return " Suit of card not found please enter a valid suit";
		break;
	}
}
string Card::getMagOfCards(cardValues m) {
	switch (m) {
	case::Two:
		return "2";
		break;
	case::Three:
		return "3";
		break;
	case::Four:
		return "4";
		break;
	case::Five:
		return "5";
		break;
	case::Six:
		return "6";
		break;
	case::Seven:
		return "7";
		break;
	case::Eight:
		return "8";
		break;
	case::Nine:
		return  "9";
		break;
	case::Ten:
		return "10";
		break;
	case::Jack:
		return "Jack";
		break;
	case::Queen:
		return "Queen";
		break;
	case King:
		return "King";
		break;
	case Ace:
		return "Ace";
		break;
	default: cout << "Card not found please select a valid card" << endl;
		break;
	}
}

