/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/

/*
	In order to compile the program command should be:
	g++ main.cpp Population.cpp PopulationManager.cpp
*/

#include <fstream>
#include <ctime>
#include <iomanip>
#include "Population.h"
#include "PopulationManager.h"

using namespace std;
time_t curtime;


int main(int argc, char const *argv[]){

	FILE* unsortedText;
	if (argv[1] == NULL)
	{
		cerr << " There is not any command line argument for N (number of rows to be sorted)." << endl;
		return 0;
	}
	int N = atoi(argv[1]);
	if(N <= 0){
		cerr << "N (number of rows to be sorted) should be positive integer." << endl;
		return 0;
	}
	unsortedText = fopen("population_by_zip_2010.csv","r");
	if (unsortedText == NULL)
	{
		cerr<< "population_by_zip_2010.csv couldn't opened." <<endl;
		return 0;
	}
	char * line= new char[250];	

	Population *populationList = new Population[N];

	fgets(line,250,unsortedText);	//Skipping first line which holds header
	

	int rowNumber=0;
	int population,zipcode,minAge,maxAge;
	string gender,geoid;
	char *tmp ;
	while( N-- > 0){
				fgets(line,250,unsortedText);
				
				int k=0;
				/* In following while block scans array and remove \r and \n characters 
				*  since it corrupts data and by using fgets i should handle it myself.
				*  This won't be in infinite loop since it's guaranteed that line have to finish with \0 character
				*  Ofcourse it adds O(N) complexity to code but in order to handle input data i use it.
				*  But we don't measure this part, we only looking complexity of Quicksort
				*/

				while(1){
					if(line[k] == '\r' || line[k] == '\n' || line[k] == '\0' ){
					line[k] = '\0';
					break;
					}
					k++;
				}

				char * linetmp = line;
			 	population=atoi(strsep(&linetmp,","));
			 	tmp = strsep(&linetmp,",");
			 	if(strcmp(tmp,"") == 0)	
			 		minAge = -1;			//If minAge is null assign it to -1 which considered as null
			 	else minAge=atoi(tmp);
			 	tmp = strsep(&linetmp,",");
			 	if (strcmp(tmp,"") == 0)
			 		maxAge= -1;				//If maxAge is null assign it to -1 which considered as null
			 	else	maxAge=atoi(tmp);
			 	tmp = strsep(&linetmp,",");
			 	if (strcmp(tmp,"") == 0)
			 		gender = string("null");	// If gender is null then assign it to "null" string.
				else	gender=string(tmp);
				
				zipcode=atoi(strsep(&linetmp,","));
				geoid = string(strsep(&linetmp,","));
			
			Population toBeSaved = Population(population,minAge,maxAge,gender,zipcode,geoid);
			populationList[rowNumber] = toBeSaved;		//Saving new row to list
			rowNumber++;
	}
	fclose(unsortedText);	//Close opened text
	PopulationManager  unsortedList;
	const clock_t begin_time = clock();	//Timer has started.
	unsortedList.quicksort(populationList,0,rowNumber-1); //Sort first N row of the input
	cout << "Time elapsed: " << float( clock () - begin_time ) * 1000 / CLOCKS_PER_SEC <<  " milliseconds" <<"\n";

	ofstream sortedText;
	sortedText.open("sortedData.csv");
	sortedText.flush();			//Clearing buffer for safer writing
	sortedText << "population,minimum_age,maximum_age,gender,zipcode,geo_id" << endl;

	for (int i = 0; i < rowNumber; i++){
		sortedText <<  populationList[i].getPopulation() << "," ;
		if (populationList[i].getMinAge() == -1)
			sortedText << ",";
		else sortedText << populationList[i].getMinAge() << ",";

		if (populationList[i].getMaxAge() == -1)
			sortedText << ",";
		else sortedText << populationList[i].getMaxAge() << ",";
		
		if (populationList[i].getGender().compare("null") == 0)
			sortedText << ",";
		else sortedText << populationList[i].getGender() << ",";
	  	sortedText << populationList[i].getZipcode() << "," << populationList[i].getGeoid() << endl ;	
	}
	sortedText.close();	

	//Clearing allocated memories
	delete [] populationList;
	delete [] line;
	return 0;
}
