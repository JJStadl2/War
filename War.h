
#pragma once
#ifndef WAR_H
#define WAR_H
#include "Deck.h"
#include "Card.h"
#include<stack>
#include<queue>
/* Author: Josiah Stadler
   Date: 11/1/20
   Course: CSC-339-01
   Purpose: This is the header file for the player class. It is used with
            the card and deck class to simulate players in the game of war.
*/
class War {
    public:
        //Defualt Constructo
        War(Deck&);
        //Deconstructor
        ~War();
        //Deals cards from playingDeck to PlayerHands
        void deal();
        //Plays the game
        void play();
        //Used to compare score returned from AreEqualMags function in card class
        void check();   
    protected:
        string name;// Holds human name  
        char playAgain; //Drives game play     
        int score;// Holds result from comparing 2 cards
        Deck playingDeck;//holds shuffled deck to play game with 
        std::queue <Card*> humanPlayerHand;//Holds human players cards for the game
        std::queue <Card*> compPlayerHand; // Holds computer players cards for the game
        std::stack <Card*> discard_Pile;//Holds all cards currently in play      
        static const int two = 2;//Used to see if either player can keep playing
};
#endif