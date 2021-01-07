
#include <iostream>
#include<random>
#include "Card.h"
#include"Deck.h"
#include "War.h"
/*
* Author: Josiah Stadler
* Date: 11/1/20
* Course: csc-339-01
* Description: This drives the game of war by creating a deck and passing that deck to the war class. 
*			   The game play is controlled by a sentinel value		
*/
using namespace std;

int main() {
	//If you want the program to run until gome is complete go to War.cpp line 77 and follow the comments for autorun
	//Creating master deck
	Deck d =  Deck();
	//Starting game
	War w = War(d);
	return(0);
}
