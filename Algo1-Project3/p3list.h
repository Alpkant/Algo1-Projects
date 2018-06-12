/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

#ifndef P3LIST_H
#define P3LIST_H

#include <iostream>
#include <cstring>
#include <vector>
#include "p3char.h"

using namespace std;

struct node{
	unsigned int key;
	char data;
	node *next;
};

class List{
	node *root;
	node *tail;
	
public:
	List();
	~List();
	void insert(BookCharacter);
	void lookup(BookCharacter & x) const;
};

#endif