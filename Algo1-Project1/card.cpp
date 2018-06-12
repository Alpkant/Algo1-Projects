/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp card.cpp cardmanager.cpp
*/
#include "card.h"

Card::Card(string keyName ,string keyClass,string keyRarity,string keySet,string keyType,int keyCost){
	Name=keyName;
	Class=keyClass;
	Rarity=keyRarity;
	Set=keySet;
	type=keyType;
	cost=keyCost;
}

Card::Card(){

}

void Card::operator=( Card& key){
    Name = key.Name;
    Class=key.Class;
	Rarity=key.Rarity;
	Set=key.Set;
	type=key.type;
	cost=key.cost;
}

Card& Card::operator[](Card& key){
	return key;
}

int Card::getCost(){
	return cost;
}

string Card::getName(){
	return Name;
}

string Card::getClass(){
	return Class;
}
string Card::getRarity(){
	return Rarity;
}
string Card::getSet(){
	return Set;
}
string Card::getType(){
	return type;
}

