/*				David Bush, CS 121, Assignment 4, 11/8/20
	---------------------------------------------------------------
	-------------------- Header File BTS Class --------------------
	---------------------------------------------------------------
*/
#pragma once

#include "StringLL.h"

const int MAX_MOVIE = 40;
// Movie Binary Search Tree Class
class MovieBST {
private:
	typedef struct TreeNode 
	{
		char movie[MAX_MOVIE]; // movie name
		int year; // movie's year
		LinkedList actorList; // list of actor names
		TreeNode* leftPtr; // ptr to left child
		TreeNode* rightPtr; // ptr to right child 
	}*TreePtr;

	TreePtr rootPtr; // root of BST
	int size; // how many movies?

	void GetMovieName(char line[], char movieName[]); 
	int GetYear(char line[]);
	int IndexOf(char s[], char c);
	void GetSubString(char s[], int start, int end, char res[]);
	void RemoveTrailingBlanks(char s[]);

	void InitBSTree() { rootPtr = NULL; size = 0; }
	void DeleteBST(TreePtr& treeptr); // deletes tree
//	void DeleteNode(TreePtr& treePtr, DATA_TYPE item);
//	void DeleteNodeItem(TreePtr& treePtr);
	
//	void ProcessLeftMost(TreePtr& treePtr, DATA_TYPE& item);
	bool IsLeaf(TreePtr treePtr);
	TreePtr SearchNodeInBST(TreePtr treePtr, char searchKey[]);

	void PrintBST_InOrder(TreePtr treePtr);
	void PrintBST_PreOrder(TreePtr treePtr);
	void PrintBST_PostOrder(TreePtr treePtr);
	void PrintRBST_InOrder(TreePtr, int depth); // reverse

public:
	MovieBST() { InitBSTree(); } // constructor
	~MovieBST(); // destructor

	bool IsEmpty() { return (rootPtr == NULL); } 

	int ReadMovies(MovieBST& MTree, string File); // Reads in File of Movies

	void AddNodeR(char newData[], int y, LinkedList act_LL);
	void AddNodeR(TreePtr& t, char newData[], int y, LinkedList act_LL);
	void SearchNode(char searchKey[]);
	int Size() { return size; }
//	void DeleteNode(DATA_TYPE data);

	void PrintTree();

	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();
	void PrintRInOrder(); // reverse
};