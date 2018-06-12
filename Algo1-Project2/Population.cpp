/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/
#include "Population.h"


Population::Population(int x,int y,int z,string i,int j ,string k){
	population = x;
	minAge = y;
	maxAge = z;
	gender = i;
	zipcode = j;
	geoid = k;
}

Population::Population(){

}

int Population::getPopulation(){
	return population;
}

int Population::getMinAge(){
	return minAge;	
}

int Population::getMaxAge(){
	return maxAge;
}

string Population::getGender(){
	return gender;
}

int Population::getZipcode(){
	return zipcode;
}

string Population::getGeoid(){
	return geoid;
}


void Population::setPopulation(int key){
population = key;
}

void Population::setMinAge(int key){
	minAge =  key;
}

void Population::setMaxAge(int key){
	maxAge = key;
}

void Population::setGender(string key){
	gender =  key;
}

void Population::setZipcode(int key){
	zipcode = key;
}

void Population::setGeoid(string key){
	geoid =  key;
}

