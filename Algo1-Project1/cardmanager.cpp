/*-------------------------
	Name: Alperen Kantarcı
	Student No: 150140140
---------------------------*/


/*
	In order to compile the program command should be:
	g++ main.cpp card.cpp cardmanager.cpp
*/

 #include "cardmanager.h"



/**
	Comparison method takes two Card item and makes logical
	comparison according to full sort.
	For full sort the precidence is CLASS,COST,NAME
	if both params are equal then it returns false to prevent 
	useless swapping
	
	insertionSort and merge methods use this method in full sort. 
*/

bool CardManager::comparison( Card& a, Card& b){
	if(a.getClass().compare(b.getClass())>0) return true;		
	if(a.getClass().compare(b.getClass())<0) return false;

	if(a.getCost()>b.getCost()) return true;
	if(a.getCost()<b.getCost()) return false;

	if(a.getName().compare(b.getName())>0) return true;
	if(a.getName().compare(b.getName())<0) return false;

	return false;
}

/**
	This method starts recurrence for mergeSort it continues to
	split half until there is one element. 

	@param type determines if it's full sort or filter sort
	true means filter ,false means full
	
*/

void CardManager::mergeSort(Card list[],bool type,int l , int r){
	if(l<r){
		int m= l+(r-l)/2;	//This prevents big integer divisions with precision problems
							// It is the same thing with the (l+r) / 2
		mergeSort(list,type,l,m);
		mergeSort(list,type,m+1,r);

		merge(list,type,l,m,r);
	}
}

/**
	The comparision and sorting method of mergeSort. 

	@param type determines if it's full sort or filter sort
	true means filter ,false means full
*/

void CardManager::merge(Card list[],bool type,int l,int m, int r){
	int i, j, k;
    int n1 = m - l + 1;		//Array size of left half 
    int n2 =  r - m;		//Array size of right half 

    Card* L = new Card[n1];	//These arrays will be used in comparison
    Card* R = new Card[n2];

    for (i = 0; i < n1; i++)	
        L[i] = list[l + i];
    for (j = 0; j < n2; j++)
        R[j] = list[m + 1+ j];

    i=0; j=0; k=l;	//i left array's location counter 
    				//j right array's location counter
    				//k holds the main array's location number so it starts with l parameter

    if (type){		//If it's filter sort
    	
    while (i < n1 && j < n2){
        if (L[i].getType().compare(R[j].getType()) <= 0){	//If left array's  element smaller than right array's element
            list[k] = L[i];									// Take left element
            i++;
        }else{
            list[k] = R[j];									//If right array's  element smaller than left array's element
            j++;											// Take right element
        }

        k++;											
    }

    /*
    	Only one of the while from next two will work and 
    	will take all of the array values to main list.Because there is nothing left
    	to compare.
    */

    while (i < n1){			//Left array still has elements take all of them to main array.
        list[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2){			//Right array still has elements take all of them to main array.
        list[k] = R[j];
        j++;
        k++;
    }

	}else{			//If it's full sort

    	while (i < n1 && j < n2){
        	if (!comparison(L[i],R[j])){	//Decide which one to take according to full sort 
           		list[k] = L[i];
            	i++;
        	}else{						
            	list[k] = R[j];
            	j++;
        	}
        
        	k++;
    		}

    	while (i < n1){		//Left array still has elements take all of them to main array.
        	list[k] = L[i];
        	i++;
        	k++;
    	}
 
   
    	while (j < n2){		//Right array still has elements take all of them to main array.
       		list[k] = R[j];
        	j++;
        	k++;
    	}
    }
}



void CardManager::insertionSort(Card list[],bool type,int size){
	if(type){
		Card key;
		int j;
		for(int i=1 ; i<size ; i++){			//Start with indice 1
			key=list[i];						//Take the element which will be inserted in sorted side of array
			j=i-1;								//Sorted side of array

			while(j>=0 && list[j].getType().compare(key.getType())>0){	//If key is smaller than element try one element left
				list[j+1] = list[j];	//Move elements one righ in order to open place for key element
				j--;
			}
			list[j+1] = key;			//The location of the key has determined change the location of key;
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

void CardManager::fullSort(Card list[],bool sortType,int size){
 	if(sortType)
 		mergeSort(list,false,0,size-1);	//False means that it's FullSort
 	else
 		insertionSort(list,false,size); 

}

void CardManager::filterSort(Card list[],bool sortType,int size){
	if(sortType)
		mergeSort(list,true,0,size-1); //True means that it's FullSort
	else
		insertionSort(list,false,size);

}