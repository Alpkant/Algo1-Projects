/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

/*
	In order to compile the program command should be:
	g++ main.cpp card.cpp cardmanager.cpp
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>

#include "card.h"
#include "cardmanager.h"

using namespace std;
time_t curtime;

int main(int argc, char const *argv[]){
	
	FILE* unsortedText;

	if(argc != 5){				
		cout << "Please give sufficient (4) arguments." ;
		return 0;
	}
	if( !strcmp(argv[1], "-full") && !strcmp(argv[1],"-filter")){
		cout << "You have to choose either -full or -filter as sorting procedure.\n";
		return 0;
	}

	if(!strcmp(argv[2], "-m") && !strcmp(argv[2],"-i") ){
		cout << "You have to choose either -i as insertion sort or -m as merge sort.\n";
		return 0;
	}

	try{									//Trying to open file
		unsortedText = fopen(argv[3],"r");
		if(unsortedText == NULL)			//Unsucecssful open throws exception
			throw "File could't open\n"; 
	}catch(const char* error){
		cout << error;
		return 0;
	}

	char * line= new char[250];			 	//Char array for every line at a time
	int sizeOfArray=0,cardNumber=0;			
	
	/*
		In order to achieve safety allocating and
		getting rid of array reallocating - transferring old array 
		to new one , first counting whole file.
		It is probably slower but easy to implement and safer.
	*/
	while(fgets(line,250,unsortedText))		
		sizeOfArray++;

	rewind(unsortedText);		//Pointer set to the head of the file

	Card* cardlist = new Card[sizeOfArray];	//Every card will be located here

	while(fgets(line,250,unsortedText)){		
		//This code block handles unwanted \r reading into string
		// which cause undefined behavior if string has any \r or \n
		// it replaces with \0 and if \r is located at 0 indice then editing string

		if(line[0] == '\r'){
			int k=0;
			while(line[k] != '\0'){
				line[k] = line[k+1];
				k++;
			}
		}
		
		int i=0;
		string Name,Class,Rarity,Set,Type;
		int cost;
		char* tokenized = strtok(line,"\t");
		while(tokenized != NULL){		   //Parsing a line.

			if(i==0)
			 	Name=string(tokenized);
			else if(i==1)
			 	Class=string(tokenized);
			else if(i==2)
			 	Rarity=string(tokenized);
			else if(i==3)
				Set=string(tokenized);
			else if(i==4)
				Type=string(tokenized);
			else if(i==5)
				cost = atoi(tokenized);

			tokenized=strtok(NULL,"\t");
			i++;
		}
		
			Card temp = Card(Name,Class,Rarity,Set,Type,cost);
			cardlist[cardNumber] = temp;		//Card has saved to array
			cardNumber++;
	}
	fclose(unsortedText);	//Input file closed.
	delete [] line; //Deletin allocated space for reading line by line

	const clock_t begin_time = clock();	//Timer has started.
	CardManager boss;

	if(strcmp(argv[1], "-full") == 0){		//If its fullsort
		if(strcmp(argv[2], "-m") == 0)		//If its full sort and merge sort
			boss.fullSort(cardlist,true,cardNumber); 

		boss.fullSort(cardlist,false,cardNumber); //Insertion and full sort
	}else{
		if (strcmp(argv[2], "-m") == 0)	    		   //If its filter sort and merge sort
			boss.filterSort(cardlist,true,cardNumber); 
		 
		boss.filterSort(cardlist,false,cardNumber);		//If its filter sort and insertion sort
	}
	cout << "Time elapsed: " << float( clock () - begin_time ) * 1000 / CLOCKS_PER_SEC <<  " milliseconds" <<"\n";
	
	ofstream sortedText;
	sortedText.open(argv[4]);
	sortedText.flush();			//Clearing buffer for safer writing
	for (int i = 0; i < cardNumber; i++){
		sortedText << cardlist[i].getName() << "\t" << cardlist[i].getClass() << "\t" << cardlist[i].getRarity() << "\t" << cardlist[i].getSet() << "\t" << cardlist[i].getType() << "\t" << cardlist[i].getCost() << "\n";
	}
	sortedText.close();
	
	delete [] cardlist;	//Delete allocated space, free the memory.
	return 0;
}