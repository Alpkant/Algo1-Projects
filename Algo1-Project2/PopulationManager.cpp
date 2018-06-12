/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/

#include "PopulationManager.h"

bool PopulationManager::comparison(Population & a , Population & b){
	if (a.getPopulation() < b.getPopulation())	return true;		//Smaller population has higher precedence
	if (a.getPopulation() > b.getPopulation())	return false;

	if (a.getGeoid().compare(b.getGeoid()) < 0)	return true;		//Smaller Geoid has higher precedence
	if (a.getGeoid().compare(b.getGeoid()) > 0)	return false;
}

void PopulationManager::quicksort(Population A [] , int p , int r ){
	if(p < r){
		int q = partition(A,p,r);

		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int PopulationManager::partition(Population A [] , int p , int r){
	Population pivot = A[r];
	int i=p-1;
	for (int j = p; j <= r-1; j++)
	{
		if ( comparison(A[j],pivot))
		{
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void PopulationManager::swap(Population & a,Population & b){
	Population temp = b;
	b=a;
	a=temp;
}