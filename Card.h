/*
Author: Josiah Stadler
Date: 9/26/20
Purpose: This is the header file for the card class that is used to create playing cards
*/
#pragma once
#ifndef CARD_H
#define CARD_H
#include<string>
#include<iostream>

using namespace std;
// Delcaring and initializing enums for the value of the cards and the suits of the cards
enum cardValues { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
enum suitValues { Heart, Club, Diamond, Spade };

class Card
{
public:

	//Default constructor
	//Card();
	//Constructor
	Card(cardValues, suitValues);
	//Deconstrutor
	~Card();
	//Checks for equal number value between 2 cards
	int areEqualMags(Card c);
	//Checks for same suit between 2 cards
	void areEqualSuits(Card);
	//prints value and suit of 1 card
	void printCard();


private:
	//returns the suit of a specific card as a string for later use in output
	string getSuit(suitValues);
	//returns the value of a specific card for later use in comparisions
	string getMagOfCards(cardValues);

protected:
	//Attributes
	string suit;// string representation of the corresponding suit enum
	cardValues value;// enum representation of value of a card
	string valueStr;// string representation of corresponding value enum


};
#endif