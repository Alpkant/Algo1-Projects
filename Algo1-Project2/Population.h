/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/
#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <cstring>

using namespace std;


class Population{
int population;
int minAge;
int maxAge;
string gender;
int zipcode;
string geoid;
public:
	Population(int ,int ,int ,string ,int ,string );
	Population();
	//Getters
	int getPopulation();
	int getMinAge();
	int getMaxAge();
	string getGender();
	int getZipcode();
	string getGeoid();
	//Setters
	void setPopulation(int);
	void setMinAge(int);
	void setMaxAge(int);
	void setGender(string);
	void setZipcode(int);
	void setGeoid(string);
};

#endif