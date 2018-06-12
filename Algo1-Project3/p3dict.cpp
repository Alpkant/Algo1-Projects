/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp p3dict.cpp p3char.cpp p3char.cpp
*/
#include "p3dict.h"
#include <cmath>

using namespace std;


Dictionary::Dictionary(){
	 vectorArray = vector<pair<unsigned int,char> > (131071);	//Store key,data pair in vector structure
	 collision = 0;
	 insertTable = new bool [131071];	//This table holds if element previously placed or not.
	 for (int i = 0; i < 131071; ++i)	
	 	insertTable[i] = false;
}

Dictionary::~Dictionary(){
	delete [] insertTable;
}

void Dictionary::insert(BookCharacter x){
	int hashed = hash(x.createKey());		//Hash the key
	int i =0 ;
	while(insertTable[hashed] == true){		//While there is collision 
		i++;
		hashed = probing(hashed,i);			//Probe until there is no collision
	}
	vectorArray[hashed] = (pair<unsigned int,char>(x.createKey(),x.getCharacter())); //Save the pair
	insertTable[hashed] = true;				//Mark as this cell used for hash table
	collision += i;							//ADd collision number
}

int Dictionary::hash(unsigned int key){
	int M = 131071;
	double A = 0.618;
	double temp = (key * A);
	temp = M * fmod(temp,1);
	return floor(temp);
}

int Dictionary::probing(int h,int i){
	unsigned long long int temp = h + (7* i) +  3*(i*i);
	return fmod(temp,131071);
}

void Dictionary::lookup(BookCharacter & x){
	int hashed = hash(x.createKey());
	int i=0;
	while(insertTable[hashed] == true || x.createKey() != vectorArray[hashed].first){
		i++;
		hashed = probing(hashed,i);
		
	}
	x.setCharacter(vectorArray[hashed].second);	//Data found get the char data from dictionary save it to book character
	insertTable[hashed] = true;
}

void Dictionary::revertInsert(){		// Reset used cells in hash table
	for (int i = 0; i < 131071; ++i)
	 	insertTable[i] = false;
}
