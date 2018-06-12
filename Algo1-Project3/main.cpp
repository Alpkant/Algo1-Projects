/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

/*
	In order to compile the program command should be:
	g++ main.cpp p3dict.cpp p3char.cpp p3char.cpp
*/

#include <fstream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "p3char.h"
#include "p3dict.h"
#include "p3list.h"

using namespace std;

int main(int argc, char const *argv[]){

	FILE* unsortedText;
	FILE* sortedInput;
	
	unsortedText = fopen("ds-set-input.txt","r");
	if (unsortedText == NULL)
	{
		cerr<< "ds-set-input.txt couldn't opened." <<endl;
		return 0;
	}

	char * inputLine= new char[250];	

	int page,line,index,numberOfRecord=0;
	char character;

	while(fgets(inputLine,250,unsortedText))
		numberOfRecord++;

	rewind(unsortedText);

	BookCharacter* classArray = new BookCharacter[numberOfRecord];
	int cursor = 0;	
	while(cursor<numberOfRecord){		//Read for block insertion

		fgets(inputLine,250,unsortedText);
		char * linetmp = inputLine;
		page=atoi(strsep(&linetmp,"\t"));
		line=atoi(strsep(&linetmp,"\t"));
		index=atoi(strsep(&linetmp,"\t"));
		character =  strsep(&linetmp,"\n")[0];
		BookCharacter toBeSaved = BookCharacter(page,line,index,character);
		classArray[cursor] = toBeSaved;
		cursor++;
	}	
	fclose(unsortedText);	//Close 

	const clock_t beginDictInsert = clock();	//Timer has started.
	Dictionary mainDict ;
	double k,tenk,hundredk;
	for (int i = 0; i < numberOfRecord; i++){
		mainDict.insert(classArray[i]);
		//Read collisions
		if (i == 999)
			k = mainDict.collision;
		else if (i == 9999)
			tenk = mainDict.collision;
		else if (i == 99999)
			hundredk = mainDict.collision;
	}
	cout << "\n\t\tDICTIONARY\n" ;
	cout << "\tInsertion finished after " << float( clock () - beginDictInsert )  / CLOCKS_PER_SEC <<  " seconds." << endl << endl;
	cout << "\tAverage number of collisions (First 1000)\t| " <<(double) k/1000 << endl;
	cout << "\tAverage number of collisions (First 10000)\t| " <<(double) tenk/10000 << endl;
	cout << "\tAverage number of collisions (First 100000)\t| " <<(double) hundredk/100000 << endl;
	cout << "\tAverage number of collisions (Overall)\t\t| " << (double) mainDict.collision/numberOfRecord << endl << endl;

	BookCharacter* classArray2 = new BookCharacter[numberOfRecord];		//Setup for dictionary lookup
	sortedInput = fopen("ds-set-lookup.txt","r");
	if (sortedInput == NULL)
	{
		cerr<< "ds-set-lookup.txt couldn't opened." <<endl;
		return 0;
	}
	numberOfRecord =0 ;
	cursor =0;
	while(fgets(inputLine,250,sortedInput))
		numberOfRecord++;

	rewind(sortedInput);

	while(cursor<numberOfRecord){			//Read for dictionary lookup
		fgets(inputLine,250,sortedInput);
		char * linetmp = inputLine;
		page=atoi(strsep(&linetmp,"\t"));
		line=atoi(strsep(&linetmp,"\t"));
		index=atoi(strsep(&linetmp,"\n"));
		BookCharacter toBeSaved = BookCharacter(page,line,index);
		classArray2[cursor] = toBeSaved;
		cursor++;
	}
	fclose(sortedInput);

	mainDict.revertInsert();
	
	const clock_t beginDictLookup = clock();	//Timer has started.
	for (int i = 0; i < numberOfRecord; ++i)
	{
		mainDict.lookup(classArray2[i]);
	}
	cout << "\tLookup finished after " << float( clock () - beginDictLookup )  / CLOCKS_PER_SEC <<  " seconds." << endl << endl;
	
	ofstream sortedOutput;
	sortedOutput.open("ds-set-output-dict.txt");
	sortedOutput.flush();			//Clearing buffer for safer writing

	for (int i = 0; i < numberOfRecord; i++)
		sortedOutput <<   classArray2[i].getPage() << "\t" << classArray2[i].getLine() << "\t" << classArray2[i].getIndex() << "\t" << classArray2[i].getCharacter()  << endl;

	sortedOutput.close();	


	unsortedText = fopen("ds-set-input.txt","r");
	if (unsortedText == NULL)
	{
		cerr<< "ds-set-input.txt couldn't opened." <<endl;
		return 0;
	}

	numberOfRecord = 0;
	while(fgets(inputLine,250,unsortedText))
		numberOfRecord++;

	rewind(unsortedText);

	BookCharacter* classArray3 = new BookCharacter[numberOfRecord];
	cursor = 0;
	while(cursor<numberOfRecord){			//Read for list insert

		fgets(inputLine,250,unsortedText);
		char * linetmp = inputLine;
		page=atoi(strsep(&linetmp,"\t"));
		line=atoi(strsep(&linetmp,"\t"));
		index=atoi(strsep(&linetmp,"\t"));
		character =  strsep(&linetmp,"\n")[0];
		BookCharacter toBeSaved = BookCharacter(page,line,index,character);
		classArray3[cursor] = toBeSaved;
		cursor++;
	}	
	fclose(unsortedText);	//Close opened text


	List mainList;
	cout << "\t\tLIST" << endl;
	const clock_t beginListInsert = clock();	//Timer has started.
	for (int i = 0; i < numberOfRecord; ++i)
		mainList.insert(classArray3[i]);

	cout << "\tInsertion finished after " << float( clock () - beginListInsert )  / CLOCKS_PER_SEC <<  " seconds." << endl;


	sortedInput = fopen("ds-set-lookup.txt","r");
	if (sortedInput == NULL)
	{
		cerr<< "ds-set-lookup.txt couldn't opened." <<endl;
		return 0;
	}


	numberOfRecord =0 ;
	cursor =0;
	while(fgets(inputLine,250,sortedInput))
		numberOfRecord++;

	BookCharacter* classArray4 = new BookCharacter[numberOfRecord];
	
	rewind(sortedInput);

	while(cursor<numberOfRecord){			//Read for list lookup
		fgets(inputLine,250,sortedInput);
		char * linetmp = inputLine;
		page=atoi(strsep(&linetmp,"\t"));
		line=atoi(strsep(&linetmp,"\t"));
		index=atoi(strsep(&linetmp,"\n"));
		BookCharacter toBeSaved = BookCharacter(page,line,index);
		classArray4[cursor] = toBeSaved;
		cursor++;
	}
	fclose(sortedInput);


	const clock_t beginListLookup = clock();	//Timer has started.
	for (int i = 0; i < numberOfRecord; ++i)
		mainList.lookup(classArray4[i]);
	
	cout << "\tLookup finished after " << float( clock () - beginListLookup )  / CLOCKS_PER_SEC <<  " seconds." << endl;

	ofstream listOutput;
	listOutput.open("ds-set-output-list.txt");
	listOutput.flush();			//Clearing buffer for safer writing

	for (int i = 0; i < numberOfRecord; i++)
		listOutput <<   classArray4[i].getPage() << "\t" << classArray4[i].getLine() << "\t" << classArray4[i].getIndex() << "\t" << classArray4[i].getCharacter()  << endl;
	
	listOutput.close(); 


	
	delete [] classArray;
	delete [] classArray2;
	delete [] classArray3;
	delete [] classArray4;
	delete [] inputLine;
	return 0;
}

 
