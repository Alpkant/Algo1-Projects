/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/
#include "p3list.h"

#include <cmath>

using namespace std;


List::List(){
	root = new node;
	root->next = NULL;
	tail = root;		
}

void List::insert(BookCharacter x){
	tail->next = new node;
	tail = tail->next;
	tail->key = x.createKey();
	tail->data = x.getCharacter();
	tail->next = NULL;
}

void List::lookup(BookCharacter & x) const{
	node* traverse = root;
	unsigned int key = x.createKey();
	while(traverse != NULL){			//Read until last element 
		if(key == traverse->key)
			x.setCharacter(traverse->data);
		traverse = traverse->next;
	}
}

List::~List(){					//Delete every allocated element from head to tail
	node* traverse=root->next;
	while(traverse!= NULL){
		delete root;
		root = traverse;
		traverse = traverse->next;
	}
	delete root;
}