/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

#ifndef P3DICT_H
#define P3DICT_H

#include <iostream>
#include <cstring>
#include <vector>
#include "p3char.h"

using namespace std;


class Dictionary{
public:
vector<pair<unsigned int,char> > vectorArray;
bool* insertTable; 
int collision;

	Dictionary();
	~Dictionary();
	//Getters
	void insert(BookCharacter);
	int hash(unsigned int );
	int probing(int,int);
	void lookup(BookCharacter &);
	void revertInsert();
};

#endif
