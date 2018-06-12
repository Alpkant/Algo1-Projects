/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp card.cpp cardmanager.cpp
*/
#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card{
	string Name;
	string Class;
	string Rarity;
	string Set;
	string type;
	int cost;
	
	public:
	Card(string ,string ,string ,string ,string ,int );
	void operator=( Card&); 
	Card& operator[] (Card& );                       // [] operator overload allows to make changes
	Card();
	//Getters
	int getCost();
	string getName();
	string getClass();
	string getRarity();
	string getSet();
	string getType();
};
#endif