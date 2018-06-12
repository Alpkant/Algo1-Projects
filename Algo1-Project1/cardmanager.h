/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp card.cpp cardmanager.cpp
*/

#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

#include "card.h"
using namespace std;

class CardManager{
	void merge(Card [],bool,int,int, int);
	bool comparison( Card&, Card&);
public:
	void fullSort(Card [],bool,int  );
	void filterSort(Card [],bool,int);
	void mergeSort(Card [],bool,int,int);
	void insertionSort(Card [],bool,int);
};

#endif