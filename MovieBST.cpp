/*				David Bush, CS 121, Assignment 4, 11/8/20
	---------------------------------------------------------------
	---------------- Implementation File BTS Class ----------------
	---------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "MovieBST.h"
#include "StringLL.h"
using namespace std;
// Deletes the Binary Search Tree
MovieBST::~MovieBST() {
	DeleteBST(rootPtr);
}
// Reads in file of movie and actor names
// doesn't work for multiple blank lines
int MovieBST::ReadMovies(MovieBST& MTree, string File) {
	ifstream fIn;
	fIn.open(File); //maybe change if not working
	if (!fIn) {
		cout << "Error in opening file\n";
		exit(-1);
	}
	// Define Variables
	const int MAX_LINE = 128; // max lines
	// char arrays to hold movie and actor names
	char line[MAX_LINE], movieName[MAX_LINE], actorName[MAX_LINE/2];
	LinkedList Actors; // linkedlist of actors
	int nMovies = 0; // Number of movies
	
	while (fIn.getline(line, MAX_LINE)) {
		GetMovieName(line, movieName);
		int year = GetYear(line);

		cout << "Movie name:\t|" << movieName << "|\n";
		cout << "\tyear: " << year << "\n";

		fIn.getline(line, MAX_LINE / 2);
		while (strlen(line) > 0) {
			strcpy(actorName, line);
			RemoveTrailingBlanks(actorName);
			cout << "\tactor name:\t|" << actorName << "\n";
			Actors.AddNode(actorName);
			//Actors.Print();

			fIn.getline(line, MAX_LINE / 2);
		}
		nMovies++; // increment movie counter by 1
		MTree.AddNodeR(movieName, year, Actors);
	}

	fIn.close();
	size = nMovies;
	return nMovies;
}
// **define
void MovieBST::GetMovieName(char line[], char movieName[]) {
	int yearStart;
	yearStart = IndexOf(line, '(');
	GetSubString(line, 0, yearStart - 1, movieName);
}
// **define
int MovieBST::GetYear(char line[]) {
	char yearString[8];
	int yearStart, yearEnd;

	yearStart = IndexOf(line, '(');
	yearEnd = IndexOf(line, ')');	
	GetSubString(line, yearStart + 1, yearEnd - yearStart, yearString);

	return atoi(yearString);
}
// **define
int MovieBST::IndexOf(char s[], char c) {
	int i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return i;
}
// **define
void MovieBST::GetSubString(char s[], int start, int end, char res[]) {
	int i;
	int iRes = 0; //index of result string

	for (i = start; i < start + end; i++) {
		res[iRes++] = s[i];
	}

	res[iRes] = '\0'; // closes string
	RemoveTrailingBlanks(res);
}
// **define
void MovieBST::RemoveTrailingBlanks(char s[]) {
	int sLen = strlen(s);

	for (int i = sLen; i >= 0; i--) {
		if (isalpha(s[i]))
			break;
		if (s[i] == ' ' || s[i] == '\t')
			s[i] = '\0';
	}
}
// Test if node is a leaf (leaf returns 1)
bool MovieBST::IsLeaf(TreePtr treePtr) {
	return ((treePtr->leftPtr == NULL) && 
		(treePtr->rightPtr == NULL));
}
// Adds node to tree recursively
void MovieBST::AddNodeR(char newData[], int y, LinkedList act_LL) {
	AddNodeR(rootPtr, newData, y, act_LL);
}
// Searchs an adds a node of data to BST 
// parameter need to be (TreePtr&t, char movie[], int year, 
void MovieBST::AddNodeR(TreePtr &t, char newData[], int y, LinkedList act_LL) {
	cout << "Test 1 \n";
	if (t == NULL)
	{
		TreePtr newPtr = new TreeNode;
		// Add new data in the new node’s data field
		strcpy(newPtr->movie, newData); // copies newData into movie
		newPtr->year = y; 
		newPtr->actorList = act_LL; // check this copies
		newPtr->leftPtr = NULL;
		newPtr->rightPtr = NULL;
		t = newPtr;
	}
	else if (strcmp(newData, t->movie) <= 0) //checks alphabetical order of movie
		AddNodeR(t->leftPtr, newData, y, act_LL);
	else
		AddNodeR(t->rightPtr, newData, y, act_LL);

}
// Deletes the Binary Search Tree, using PostOrder traversal
void MovieBST::DeleteBST(TreePtr& treePtr) {
	// checks if tree is NULL
	if (treePtr != NULL)
	{
		// Recursion to check each left and right subtrees
		DeleteBST(treePtr->leftPtr);
		DeleteBST(treePtr->rightPtr);
		delete treePtr;
		treePtr = NULL; 
	}
}
// Search for Node with data 'key'
void MovieBST::SearchNode(char searchKey[]) {
	TreePtr srchPtr = NULL;

	srchPtr = SearchNodeInBST(rootPtr, searchKey);
	if (srchPtr != NULL)
	{
		cout << "\n Node: " << srchPtr->movie << " found in the BST\n";
	}
	else
	{
		cout << "\n Node: " << searchKey << " not found" << endl;
	}
}
// **DEFINE
MovieBST::TreePtr MovieBST::SearchNodeInBST(TreePtr treePtr, char key[])
{
	if (treePtr != NULL) {
		if (key == treePtr->movie)
			return treePtr;
		else if (key < treePtr->movie)
			// Search for "key" in left subtree
			SearchNodeInBST(treePtr->leftPtr, key);
		else // (key > tree_ptr->data)
		// Search for "key" in right subtree
			SearchNodeInBST(treePtr->rightPtr, key);
	}
	else {
		return NULL;
	}
}
// **DEFINE
void MovieBST::PrintTree()
{
	PrintBST_InOrder(rootPtr);
}
// Print BST using InOrder traversal
void MovieBST::PrintInOrder()
{
	PrintBST_InOrder(rootPtr);
}
void MovieBST::PrintBST_InOrder(
	TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print left BST subtree
		PrintBST_InOrder(treePtr->leftPtr);
		// Print Root node data
		cout << treePtr->movie << "\n";
		// Print right BST subtree
		PrintBST_InOrder(treePtr->rightPtr);
	}
}
// Print BST using PreOrder traversal
void MovieBST::PrintPreOrder()
{
	PrintBST_PreOrder(rootPtr);
}
void MovieBST::PrintBST_PreOrder(TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print node data
		cout << treePtr->movie << endl;
		// Print left subtree
		PrintBST_PreOrder(treePtr->leftPtr);
		// Print right subtree
		PrintBST_PreOrder(treePtr->rightPtr);
	}
}
// Print BST using PostOrder traversal
void MovieBST::PrintPostOrder()
{
	PrintBST_PostOrder(rootPtr);
}
void MovieBST::PrintBST_PostOrder(
	TreePtr treePtr)
{
	if (treePtr != NULL)
	{
		// Print left BST subtree
		PrintBST_PostOrder(treePtr->leftPtr);
		// Print right BST subtree
		PrintBST_PostOrder(treePtr->rightPtr);
		// Print node data
		cout << treePtr->movie << endl;
	}
}
// Print BST using InOrder traversal
void MovieBST::PrintRInOrder()
{
	PrintRBST_InOrder(rootPtr, 0);
}
void MovieBST::PrintRBST_InOrder(
	TreePtr treePtr, int depth)
{
	const int INDENT = 4;
	if (treePtr != NULL) {
		// Print right BST subtree
		PrintRBST_InOrder(treePtr->rightPtr, depth + 1);
		// Print data in root node
		//cout << setw(INDENT*depth) << " ";
		for (int i = 0; i < INDENT * depth; i++) cout << " ";
		cout << treePtr->movie << endl;
		// Print left BST subtree
		PrintRBST_InOrder(treePtr->leftPtr, depth + 1);
	}
}