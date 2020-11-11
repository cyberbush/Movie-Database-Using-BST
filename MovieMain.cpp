/*			David Bush, CS 121, Assignment 4, 11/8/20  
	---------------------------------------------------------------
	--------------------- Main File Movie BTS ---------------------
	---------------------------------------------------------------
	To compile g++ MovieMain.cpp MovieBST.cpp StringLL.cpp -o MovieMain

	To Run ./MovieMain
*/
#include <iostream>
#include "MovieBST.h"
#include "StringLL.h"
using namespace std;

// Works with creating tree and printing tree
// To DO
// Searching tree
// need to check if node exists and dont addNode if true

int main(int argc, char** argv) {
	// Reads in file name from command line and saves it
	string inFile = "";
	if (argc == 2)
		inFile = argv[1];
	else {
		cout << "Error with inputing file try again.\n";
		exit(-1);
	}
	
	MovieBST M1;
	LinkedList actorL1, actorL2, actorL3;
//	M1.ReadMovies(M1, inFile);
	char movie1[20] = "The Dark Knight";
	char movie2[20] = "Animal Kingdom";
	char movie3[20] = "Jeff Is Cool";
	int year1 = 1990, year2 = 2000, year3 = 2020;

//	cout << "Actor List 1\n";
	actorL1.AddNode("Bob");
	actorL1.AddNode("Sally");
	actorL1.AddNode("Harry");
//	actorL1.Print();

//	cout << "Actor List 2\n";
	actorL2.AddNode("Jay");
	actorL2.AddNode("Rob");
	actorL2.AddNode("Sarah");	
//	actorL2.Print();

//	cout << "Actor List 3\n";
	actorL3.AddNode("Kylie");
	actorL3.AddNode("Bill");
	actorL3.AddNode("Dave");
//	actorL3.Print();



	M1.AddNodeR(movie1, year1, actorL1);	

	return 0;
}