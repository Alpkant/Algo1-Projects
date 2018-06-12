/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

#ifndef P3CHAR_H
#define P3CHAR_H

#include <iostream>
#include <cstring>

using namespace std;


class BookCharacter{
int page;
int line;
int index;
char character;
public:
	BookCharacter(int ,int ,int ,char );
	BookCharacter(int ,int ,int);
	BookCharacter();
	//Getters
	int getPage();
	int getLine();
	int getIndex();
	char getCharacter();
	int createKey();
	//Setters
	void setCharacter(char);
};

#endif