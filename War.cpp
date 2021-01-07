#include <iostream>
#include<cstdio>
#include<string>
#include "War.h"
#include "Deck.h"
#include"Card.h"
using namespace std;
//Passed unsheffled master deck and prompts human for info
War::War(Deck& master) {
	this->playingDeck = master;
	playingDeck.shuffle();
	while (toupper(this->playAgain) != 'P') {
		cout << "WAR TIME... Enter your name human: " << endl;
		cin >> this->name;
		cout << "Welcome to WAR " << this->name << ". Let's play!" << endl;
		cout << "Dealing cards to " << this->name << " & the computer player" << endl;		
		cout << " Enter 'P' to start playing or close the program: ";
		cin >> this->playAgain;

	}
	//Extra shuffle because provided more interesting game
	playingDeck.shuffle();
	this->deal();
	this->play();	
}
War::~War() {

}
//Deals cards one at a time to each player.
void War::deal() {	
	
	for (int i = 0; i < 52; i++) {
		if (i % 2 == 0) {
			this->humanPlayerHand.push(this->playingDeck.draw());
		}
		else {
			this->compPlayerHand.push(this->playingDeck.draw());
		}
	}
}
void War::play() {
	this->playAgain = 'Y';	
	while (!this->humanPlayerHand.empty() && !this->compPlayerHand.empty()){	

		//Human quits, or either player does not have neough cards to keep playing
		if ((toupper(playAgain)!= 'Y')) {
			cout << "You have decided to quit" << endl;
			cout << this-> name<<"'s card count is: "<<this->humanPlayerHand.size() << endl;
			cout << "The computer's card count is: "<< this->compPlayerHand.size() << endl;
			if (this->humanPlayerHand.size() > this->compPlayerHand.size()) {
				cout << this->name << " wins!!" << endl;
			}
			else {
				cout << "The computer wins" << endl;
			}
			cout << "GAME OVER" << endl;
			exit(0);
		}	

		//output counts of each hand and discard pile
		cout << "==========================COUNTS FOR THIS ROUND===========================================" << endl;
		cout << this->name << "'s card count: " << humanPlayerHand.size() << endl;
		cout << "Computer's card count: " << compPlayerHand.size() << endl;		
		cout << "================================CARDS OUT=================================================" << endl;

		//display one card of each player
		cout << this->name << " drew a =====>";
		this->humanPlayerHand.front()->printCard();
		cout << "The computer drew a =====>";
		this->compPlayerHand.front()->printCard();

		//Stores result from AreequalMags function from card class to compare card values
		this-> score = this->humanPlayerHand.front()->areEqualMags(*this->compPlayerHand.front());

		//Add both cards to discard pile until results confirmed
		this->discard_Pile.push(this->humanPlayerHand.front());
		this->discard_Pile.push(compPlayerHand.front());
		this->humanPlayerHand.pop();		
		this->compPlayerHand.pop();
		this->check();
		if (this->humanPlayerHand.empty()) {
			cout << this->name << " is out of cards. the computer wins!!!" << endl;
		}
		else if (this->compPlayerHand.empty()) {
			cout << "The computer player is out of cards, " << this->name << " wins!!!" << endl;
		}
		//Used to control rate of play. 
		cout << "Enter Y to play another round: ";
		cin >> this-> playAgain;
		
		//If you want to run the game without confimation/pause between rounds comment out above two lines and uncomment below line
		//playAgain = 'Y';
				
	} 
}
void War::check() {

	//returned int value from AreEqualMags function in card class is evaluated to decide on winner of round.
	if (this->score < 0) {
		cout << this->name << " won the round" << endl;

		//All cards in the discard pile added to human player hand
		while (!this->discard_Pile.empty()) {
			this->humanPlayerHand.push(this->discard_Pile.top());
			this->discard_Pile.pop();
		}
	}
	else if (this->score > 0) {
		cout << "The computer won the round" << endl;

		//All cards from discard pile added to computer player hand
		while (!this->discard_Pile.empty()) {
			this->compPlayerHand.push(this->discard_Pile.top());
			this->discard_Pile.pop();
		}
	}
	else {
		cout << "========THIS IS WAR===========" << endl;
		//Human quits, or either player does not have neough cards to keep playing
		if ((humanPlayerHand.size() < two) || (compPlayerHand.size() < two)) {
			if (humanPlayerHand.size() < two) {
				cout << this->name << " You do not have enough cards to keep playing" << endl;
				cout << "the computer wins!"<<endl;
			}
			else if (compPlayerHand.size() < two) {
				cout << "The computer does not have enough cards to keep playing" << endl;
				cout << this->name << " wins!"<<endl;
			}
			cout << "GAME OVER" << endl;
			exit(0);
		}

		//Each player puts one card face down in discard pile
		this->discard_Pile.push(this->humanPlayerHand.front());
		this->discard_Pile.push(this->compPlayerHand.front());
		this->humanPlayerHand.pop();		
		this->compPlayerHand.pop();
		
		//Each player displays one card, face up, that is used for war
		cout << this->name << " drew a=====> ";
		this->humanPlayerHand.front()->printCard();		
		cout << "The computer drew a=====> ";
		this->compPlayerHand.front()->printCard();		

		//Test the card to see who wins war
		score = this->humanPlayerHand.front()->areEqualMags(*this->compPlayerHand.front());	
		this->discard_Pile.push(this->humanPlayerHand.front());
		this->discard_Pile.push(this->compPlayerHand.front());
		this->humanPlayerHand.pop();
		this->compPlayerHand.pop();
		//Calls check function again test new cards' values
		check();
	}
	

}
	

