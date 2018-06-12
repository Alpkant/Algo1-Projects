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


using namespace std;

struct node
{
	string key;
	int age;
	char gender;
	struct node *left,*right,*parent;
	char colour;
	int number_of_man=0;
	int number_of_woman=0;

	node(string k,int a,char g,char c);
};

node::node(string k,int a,char g,char c = 'R'){
	key = k;
	age = a;
	gender = g;
	colour = c;
	if(gender == 'F')
		number_of_woman=1;
	else if (gender == 'M')
		number_of_man=1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

node *root;


void tree_insert(node *toBeInserted){		//Binary search tree insert
	if (root == NULL) 
		root = toBeInserted;
	else{
		node* traverse= root;
		bool flag= false;
		while(flag != true){
			if(toBeInserted->gender == 'F')
				traverse->number_of_woman+=1;
			else 
				traverse->number_of_man+=1;

			if (toBeInserted->key < traverse->key){         //If lesser than 
                if (traverse->left == NULL){	
                    traverse->left = toBeInserted;
                    toBeInserted->parent = traverse;
                    flag = true;
                }
                else                                       //If left is empty insert it
                    traverse = traverse->left;				// Advance to left child
                
            }
            else{                                   //If higher than
                if (traverse->right == NULL){		//If right is empty insert it
                    traverse->right = toBeInserted;
                    toBeInserted->parent = traverse;
                    flag = true;		
                }
                else traverse = traverse->right;    // Advance to right child                                     
            }
		}
	}
}

void leftRotateLeft(node *toBeInserted){
	node* a = toBeInserted->parent;					// a, b, c nodes according to the course slide
	node* b = toBeInserted;
	node* c = toBeInserted->parent->parent;

	int number_of_man_a =a->number_of_man;
	int number_of_woman_a =a->number_of_woman;
	int number_of_man_b =b->number_of_man;
	int number_of_woman_b =b->number_of_woman;

    if (b->left != NULL){
    number_of_man_a = number_of_man_a - number_of_man_b + b->left->number_of_man;
    number_of_woman_a = number_of_woman_a - number_of_woman_b + b->left->number_of_woman;
    
    number_of_man_b = number_of_man_b - b->left->number_of_man + number_of_man_a;
    number_of_woman_b = number_of_woman_b - b->left->number_of_woman + number_of_woman_a;
    }else{
    number_of_man_a = number_of_man_a - number_of_man_b;
    number_of_woman_a = number_of_woman_a - number_of_woman_b;
    
    number_of_man_b = number_of_man_b + number_of_man_a; 
    number_of_woman_b = number_of_woman_b + number_of_woman_a;
    }

		
    //Number of man and woman calculated for a and b and will be saved in the nodes
    a->number_of_man = number_of_man_a;		
    a->number_of_woman = number_of_woman_a;

    b->number_of_man = number_of_man_b;
    b->number_of_woman = number_of_woman_b;





	b->parent = c;
	c->left = b;
	a->right = b->left;
	if(b->left != NULL){
        b->left->parent = a;	
	}
 
    a->parent = b;
    b->left = a;

    return;
}

void leftRotateRight(node *toBeInserted){
	node* a = toBeInserted->parent;					// a, b, c nodes according to the course slide
	node* b = toBeInserted;
	node* c = toBeInserted->parent->parent;

	int number_of_man_a =a->number_of_man;
	int number_of_woman_a =a->number_of_woman;
	int number_of_man_b =b->number_of_man;
	int number_of_woman_b =b->number_of_woman;

    if (b->right != NULL){
    number_of_man_a = number_of_man_a - number_of_man_b + b->right->number_of_man;
    number_of_woman_a = number_of_woman_a - number_of_woman_b + b->right->number_of_woman;
    
    number_of_man_b = number_of_man_b - b->right->number_of_man + number_of_man_a;
    number_of_woman_b = number_of_woman_b - b->right->number_of_woman + number_of_woman_a;
    }else{
    number_of_man_a = number_of_man_a - number_of_man_b;
    number_of_woman_a = number_of_woman_a - number_of_woman_b;
    
    number_of_man_b = number_of_man_b + number_of_man_a; 
    number_of_woman_b = number_of_woman_b + number_of_woman_a;
    }

		
    //Number of man and woman calculated for a and b and will be saved in the nodes
    a->number_of_man = number_of_man_a;		
    a->number_of_woman = number_of_woman_a;

    b->number_of_man = number_of_man_b;
    b->number_of_woman = number_of_woman_b;


	b->parent = c;
	c->right = b;
	a->left = b->right;
	if(b->right != NULL){
        b->right->parent = a;	
	}
 
    a->parent = b;
    b->right = a;

    return;
}

void rightRotateLeft(node *toBeInserted){
	node* b = toBeInserted->parent;
    node* c = toBeInserted->parent->parent;

    int number_of_man_c =c->number_of_man;
	int number_of_woman_c =c->number_of_woman;
	int number_of_man_b =b->number_of_man;
	int number_of_woman_b =b->number_of_woman;

	if (b->right != NULL){
    number_of_man_c = number_of_man_c - number_of_man_b + b->right->number_of_man;
    number_of_woman_c = number_of_woman_c - number_of_woman_b + b->right->number_of_woman;
    
    number_of_man_b = number_of_man_b - b->right->number_of_man + number_of_man_c;
    number_of_woman_b = number_of_woman_b - b->right->number_of_woman + number_of_woman_c;
    }else{
    number_of_man_c = number_of_man_c - number_of_man_b;
    number_of_woman_c = number_of_woman_c - number_of_woman_b;
    
    number_of_man_b = number_of_man_b + number_of_man_c; 
    number_of_woman_b = number_of_woman_b + number_of_woman_c;
    }

    //Number of man and woman calculated for a and b and will be saved in the nodes
    c->number_of_man = number_of_man_c;		
    c->number_of_woman = number_of_woman_c;

    b->number_of_man = number_of_man_b;
    b->number_of_woman = number_of_woman_b;



    c->left = b->right;
    if (b->right != NULL){
        b->right->parent = c;
    }

    c->colour = 'R';
    if (c == root){				// IF c is root then make the b root.
        root = b;
        b->parent = NULL;
    }			
    else{						//If c is not root
        if (c == c->parent->left){		//If c is a left child
            c->parent->left = b;		
            b->parent = c->parent;
        }	
        else{							//If c is a right child
            c->parent->right = b;
            b->parent = c->parent;
        }
    }
    c->parent = b;			  //Make b's parent c 
    b->right = c;			  //Right child of the b is c
    b->colour = 'B';			  //Since c is red make the b black
    return;
}

void rightRotateRight(node *toBeInserted){ // All lefts in the first function changed to right
											// All rights in the first function changed to left 
	node* b = toBeInserted->parent;
    node* c = toBeInserted->parent->parent;

    int number_of_man_c =c->number_of_man;
	int number_of_woman_c =c->number_of_woman;
	int number_of_man_b =b->number_of_man;
	int number_of_woman_b =b->number_of_woman;

    if (b->left != NULL){
    number_of_man_c = number_of_man_c - number_of_man_b + b->left->number_of_man;
    number_of_woman_c = number_of_woman_c - number_of_woman_b + b->left->number_of_woman;
    
    number_of_man_b = number_of_man_b - b->left->number_of_man + number_of_man_c;
    number_of_woman_b = number_of_woman_b - b->left->number_of_woman + number_of_woman_c;
    }else{
    number_of_man_c = number_of_man_c - number_of_man_b;
    number_of_woman_c = number_of_woman_c - number_of_woman_b;
    
    number_of_man_b = number_of_man_b + number_of_man_c; 
    number_of_woman_b = number_of_woman_b + number_of_woman_c;
    }

    //Number of man and woman calculated for a and b and will be saved in the nodes
    c->number_of_man = number_of_man_c;		
    c->number_of_woman = number_of_woman_c;

    b->number_of_man = number_of_man_b;
    b->number_of_woman = number_of_woman_b;



    c->right = b->left;
    if (b->left != NULL){
        b->left->parent = c;
    }

    c->colour = 'R';
    if (c == root){				// IF c is root then make the b root.
        root = b;
        b->parent = NULL;
    }			
    else{						//If c is not root
        if (c == c->parent->right){		//If c is a left child
            c->parent->right = b;		
            b->parent = c->parent;
        }	
        else{							//If c is a right child
            c->parent->left = b;
            b->parent = c->parent;
        }
    }
    c->parent = b;			  //Make b's parent c 
    b->left = c;			  //Right child of the b is c
    b->colour = 'B';			  //Since c is red make the b black
    return;
}

void RBInsert( node *toBeInserted){
	tree_insert(toBeInserted);			//First of all binary search insert

	while(toBeInserted!=root && toBeInserted->parent->colour == 'R' ){ //If parent is Red and not root
		if(toBeInserted->parent == toBeInserted->parent->parent->left){ //If our parent connected from left to his
			node* uncle = toBeInserted->parent->parent->right;			   //  uncle of the toBeInserted 
			if( uncle!= NULL && uncle->colour == 'R'){									   //CASE 1 colouring
				node* current  = toBeInserted;
				node* currenty = toBeInserted->parent->parent->right;
				while(current->parent->parent != NULL){ 				//Lookup all nodes for recolouring
					currenty->colour = 'B';					//Make it self Black
					current->parent->colour = 'B';			//Make parent Black
					current->parent->parent->colour = 'R';	//Make grand parent red
					current = current->parent->parent;			//Switch to the grandparent
					if(current->parent == NULL || current->parent->parent == NULL) //Parent of new current or grand parent is  empty finish colouring	
						break;
					else if(current->parent->parent->right == current->parent)
						currenty = current->parent->parent->left;		//Choose other uncle
					else
						currenty = current->parent->parent->right;
				}
			}else if(toBeInserted == toBeInserted->parent->right){     //CASE 2 
				leftRotateLeft(toBeInserted);
	                /*
					After left rotating for case 2 it fall into case 3 so we need to do operations for the case 3
                */
                rightRotateLeft(toBeInserted->left);
			}else{													   //CASE 3 
				rightRotateLeft(toBeInserted);
			}
		}else {				//Right and left swapped and the same operations of the first if block with swapped left and right
			node* uncle = toBeInserted->parent->parent->left;			   //  uncle of the toBeInserted 
			if( uncle!= NULL && uncle->colour == 'R'){									   //CASE 1 colouring
				node* current  = toBeInserted;
				node* currenty = toBeInserted->parent->parent->left;
				while(current->parent->parent != NULL){ 				//Lookup all nodes for recolouring
					currenty->colour = 'B';					//Make it self Black
					current->parent->colour = 'B';			//Make parent Black
					current->parent->parent->colour = 'R';	//Make grand parent red
					current = current->parent->parent;			//Switch to the grandparent
					if(current->parent == NULL || current->parent->parent == NULL) //Parent of new current or grand parent is  empty finish colouring	
						break;
					else if(current->parent->parent->left == current->parent)
						currenty = current->parent->parent->left;		//Choose other uncle
					else
						currenty = current->parent->parent->left;
				}
			}else if(toBeInserted == toBeInserted->parent->left){     //CASE 2 
				leftRotateRight(toBeInserted);	
                /*
					After left rotating for case 2 it fall into case 3 so we need to do operations for the case 3
                */
                rightRotateRight(toBeInserted->right);
			}else{													   //CASE 3 
				rightRotateRight(toBeInserted);
			}	
		}
	}
	root->colour = 'B';
}

node* man_nth(node* x,int i){
	if(x == NULL){
		node* nullRecord = new node("Dummy",0,'U');
		return nullRecord;
	}
	int k=0;
	if(x->left != NULL)
		k = x->left->number_of_man ;

	if(x->gender == 'M')
		k+=1;

	if (i==k && x->gender == 'M' ) return x;
	return (i<=k) ? man_nth(x->left,i) : man_nth(x->right,i-k);
}

node* woman_nth(node* x,int i){
	if(x == NULL){
		node* nullRecord = new node("Dummy",0,'U');
		return nullRecord;
	}
	int k=0;
	if(x->left != NULL)
		k = x->left->number_of_woman ;

	if(x->gender == 'F')
		k+=1;

	if (i==k && x->gender == 'F' ) return x;
	return (i<=k) ? woman_nth(x->left,i) : woman_nth(x->right,i-k);
}

void printInorder(node *traverse, bool isLeft,int indent)
{
	if (traverse == NULL )
		return;

	printInorder(traverse->left,true,indent+6);
	if(traverse == root){
		cout << "(" << traverse->colour << ")" <<traverse->key << "-" << traverse->age << "-" << traverse->gender << endl;
	}else if(isLeft == true){
		cout << setw(indent) << ' ';
		cout << "┌--";
		cout << "(" << traverse->colour << ")" <<traverse->key << "-" << traverse->age << "-" << traverse->gender << endl;
	}else{
		cout << setw(indent) << ' ';
		cout << "└--";
		cout << "(" << traverse->colour << ")" <<traverse->key << "-" << traverse->age << "-" << traverse->gender << endl;
	}
	printInorder(traverse->right,false,indent+6);

}

int main(int argc, char const *argv[]){
	
	FILE* unsortedText;

	if(argc !=2){
		cerr<< "You only have to give input file name in console." <<endl;
		return 0;
	}

	unsortedText = fopen(argv[1],"r");

	if (unsortedText == NULL){
		cerr<< argv[1] << " couldn't opened." <<endl;
		return 0;
	}

	char * inputLine= new char[250];	

	int age,numberOfRecord=0;
	string name;
	char gender;

	while(fgets(inputLine,250,unsortedText))
		numberOfRecord++;

	rewind(unsortedText);
	int cursor = 0;
	while(cursor<numberOfRecord){		//Read  from file
		fgets(inputLine,250,unsortedText);
		char * linetmp = inputLine;
		name = string(strsep(&linetmp,"\t"));
		gender = strsep(&linetmp,"\t")[0];
		age=atoi(strsep(&linetmp,"\n"));
		node *tobeAdded = new node(name,age,gender);
		RBInsert(tobeAdded);
		cursor++;
	}	
	fclose(unsortedText);	//Close 
	printInorder(root,false,0);

    cout << endl <<"3rd woman: " << woman_nth(root,3)->key << endl;
	cout << "4th man: " << man_nth(root,4)->key << endl; 
	return 0;
}