/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/
#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "Population.h"
using namespace std;



class PopulationManager{
public:
	void quicksort(Population [],int ,int );
	int	partition(Population [],int ,int);
	void swap(Population &,Population &);
	bool comparison(Population  &,Population &);
};


#endif