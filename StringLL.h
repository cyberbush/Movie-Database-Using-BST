/* David Bush, Assignment 4, CS 121, Bolden, 11/8/20
------------------------------------------------------------------
----------------------- String LL Header -------------------------
------------------------------------------------------------------
*/
#pragma once
#include <stdbool.h>
#include <iostream>
using namespace std;

class LinkedList
{
private:
	// structure that holds the character data and next pointer
	struct node {
		string name;
		node* next;
	};
	typedef node* nodeptr;

	nodeptr head; // top of list

	int size;
public:
	// Constructor
	LinkedList() {
		head = NULL;
		size = 0;
	}
	// Destructor
	~LinkedList() {
		nodeptr curr = head;
		nodeptr prev;

		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}
	void AddNode(string x); // function to add a node to list
	void DeleteNode(string x); // function to delete a node from list
	string FirstNode(); // function  to return first node of list
	void Print(); // function for printing each node in list
	int Size(); // function for returning size of list
};
