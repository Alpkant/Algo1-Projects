#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
time_t curtime;



class Card{
string Name;
string Class;
string Rarity;
string Set;
string type;
int cost;
public:
Card(string ,string ,string ,string ,string ,int );
void operator=( Card&); 
Card& operator[] (Card& );                       // [] operator overload allows to make changes

Card();
int getCost();
string getName();
string getClass();
string getRarity();
string getSet();
string getType();
};

Card::Card(string keyName ,string keyClass,string keyRarity,string keySet,string keyType,int keyCost){
	Name=keyName;
	Class=keyClass;
	Rarity=keyRarity;
	Set=keySet;
	type=keyType;
	cost=keyCost;
}

Card::Card(){

}

void Card::operator=( Card& key){
    Name = key.Name;
    Class=key.Class;
	Rarity=key.Rarity;
	Set=key.Set;
	type=key.type;
	cost=key.cost;
    //return *this;
}

Card& Card::operator[](Card& key){
	return key;
}

int Card::getCost(){
	return cost;
}

string Card::getName(){
	return Name;
}

string Card::getClass(){
	return Class;
}
string Card::getRarity(){
	return Rarity;
}
string Card::getSet(){
	return Set;
}
string Card::getType(){
	return type;
}

bool comparison( Card& a, Card& b){
	if(a.getClass().compare(b.getClass())>0) return true;
	if(a.getClass().compare(b.getClass())<0) return false;

	if(a.getCost()>b.getCost()) return true;
	if(a.getCost()<b.getCost()) return false;

	if(a.getName().compare(b.getName())>0) return true;
	if(a.getName().compare(b.getName())<0) return false;

	return false;
}	


void insertionSort(Card list[],bool type,int size){
	if(type){
		Card key;
		int j;
		for(int i=1 ; i<size ; i++){
			key=list[i];
			j=i-1;

			while(j>=0 && list[j].getType().compare(key.getType())>0){
				list[j+1] = list[j];
				j--;
			}
			list[j+1] = key;
		}
	}else{
		Card key;
		int j;
		for(int i=1 ; i<size ; i++){
			key=list[i];
			j=i-1;

			while(j>=0 && comparison(list[j],key) ){
				list[j+1] = list[j];
				j--;
			}
			list[j+1] = key;
		}

	

	}
}

void merge(Card list[],bool type,int l,int m, int r){
	
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    Card* L = new Card[n1];
    Card* R = new Card[n2];

    for (i = 0; i < n1; i++)
        L[i] = list[l + i];
    for (j = 0; j < n2; j++)
        R[j] = list[m + 1+ j];

    i=0; j=0; k=l;


    if (type)
    {
    	
    while (i < n1 && j < n2)
    {
        if (L[i].getType().compare(R[j].getType()) <= 0)
        {
            list[k] = L[i];
            i++;
        }
        else
        {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        list[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        list[k] = R[j];
        j++;
        k++;
    }


    }else{

    	while (i < n1 && j < n2)
    {
        if (!comparison(L[i],R[j]))
        {
            list[k] = L[i];
            i++;
        }
        else
        {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        list[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        list[k] = R[j];
        j++;
        k++;
    }


    }

}

void mergeSort(Card list[],bool type,int l , int r){
	if(l<r){
		int m= l+(r-l)/2;

		mergeSort(list,type,l,m);
		mergeSort(list,type,m+1,r);

		merge(list,type,l,m,r);
	}
}




class CardManager{

public:
	void fullSort(Card &,char,int  );
	void filterSort(Card &,char,int);


};

void CardManager::fullSort(Card& list,char sortType,int size){

}

void CardManager::filterSort(Card& list,char sortType,int size){


}

int main(int argc, char const *argv[])
{
	
	//FILE* unsortedText;
	//FILE* sortedText;


	if(argc != 5){				
		cout << "Please give sufficient (4) arguments." ;
		return 0;
	}
	if( !strcmp(argv[1], "-full") && !strcmp(argv[1],"-filter")  ){
		cout << "You have to choose either -full or -filter as sorting procedure.\n";
		return 0;
	}

	if(!strcmp(argv[2], "-m") && !strcmp(argv[2],"-i") ){
		cout << "You have to choose either -i as insertion sort or -m as merge sort.\n";
		return 0;
	}

	/*try{
		unsortedText = fopen(argv[3],"r");
		if(unsortedText == NULL)
			throw "File could't open\n"; 
	}catch(const char* error){
		cout << error;
		return 0;
	}*/
	ifstream unsortedText;
	unsortedText.open(argv[3]);

	char * line= new char[250];
	int sizeOfArray=0,cardNumber=0;
	
	unsortedText.getline(line,250);
	cout << line;
	unsortedText.getline(line,250);
	cout << line;

	/*
	while(fgets(line,200,unsortedText))
		sizeOfArray++;

	rewind(unsortedText);

	Card* alperen = new Card[sizeOfArray+1];

	while(fgets(line,250,unsortedText)){
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
			//cout << Name << "\t" << Class << "\t"<< Rarity << "\t"<< Set << "\t"<< Type << "\t"<< cost << endl;
			  Card temp = Card(Name,Class,Rarity,Set,Type,cost);
			  alperen[cardNumber] = temp;
			  cardNumber++;
	}
	fclose(unsortedText);

	//sortedText = fopen(argv[4],"w");

	
	const clock_t begin_time = clock();
	mergeSort(alperen,false,0,cardNumber);
	
	ofstream sortedText;
	sortedText.open(argv[4]);
	sortedText.flush();
	for (int i = 0; i < cardNumber; i++)
	{
		sortedText << alperen[i].getName() << "\t" << alperen[i].getClass() << "\t"  << alperen[i].getRarity() << "\t"  << alperen[i].getSet() << "\t" << alperen[i].getType() << "\t" << alperen[i].getCost() << "\n\r";		   
	}
	sortedText.close();
	

	for (int i = 0; i < cardNumber; i++)
	{
		cout << setw(25)  << alperen[i].getName() << "\t"  << setw(25) << alperen[i].getClass() << "\t" << setw(25)  << alperen[i].getRarity() << "\t" << setw(25)  << alperen[i].getSet() << "\t" << setw(25) << alperen[i].getType() << "\t" << alperen[i].getCost() << "\n";
	}
	cout << alperen[0].getName() << " " <<alperen[1].getName();
	cout << "Time : " << float( clock () - begin_time ) << "\n";
	delete [] alperen;*/
	return 0;
}