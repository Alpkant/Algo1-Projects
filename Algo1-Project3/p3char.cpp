/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp p3dict.cpp p3char.cpp p3char.cpp
*/
#include "p3char.h"


BookCharacter::BookCharacter(int x ,int y,int z ,char i){
	page = x;
	line = y;
	index = z;
	character = i;
}

BookCharacter::BookCharacter(int x ,int y,int z ){
	page = x;
	line = y;
	index = z;
}

BookCharacter::BookCharacter(){

}


int BookCharacter::getPage(){
	return page;
}

int BookCharacter::getLine(){
	return line;	
}

int BookCharacter::getIndex(){
	return index;
}

char BookCharacter::getCharacter(){
	return character;
}

int BookCharacter::createKey(){
	return page*10000+line*100+index;
}

void BookCharacter::setCharacter(char key){
	character = key;
}



