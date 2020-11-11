/* David Bush, InFix PostFix Assignment 2, CS 121, Bolden, 10/10/20
------------------------------------------------------------------
-------------------- String LL Implentation ----------------------
------------------------------------------------------------------
*/
#include <stdbool.h>
#include <iostream>
#include "StringLL.h"
using namespace std;

// Function for adding a node to the front of a linked list
void LinkedList::AddNode(string x) {
	nodeptr n;
	//allocate
	n = new node;
	n->name = x;
	size++;

	if (head == NULL) {
		head = n;
		n->next = NULL;
	}
	else {
		nodeptr tmp = head;
		n->next = tmp;
		head = n;
	}
}
// Function for deleting item x of a linked list
void LinkedList::DeleteNode(string x) {
	nodeptr prev, curr = head;

	while (curr != NULL && x != curr->name) {
		prev = curr;
		curr = curr->next;
	}
	if (x == curr->name)
	{
		if (curr == head)
			head = head->next;
		else
			prev->next = curr->next;
		delete curr;
		size--;
	}
}
// Function for returning first item of a linked list
string LinkedList::FirstNode()
{
	return head->name;
}
// Function for printing the contents of a linked list
void LinkedList::Print()
{
	nodeptr p = head;
	if (p != NULL) {
		while (p != NULL)
		{
			cout << p->name << "\n";
			p = p->next;
		}
	}
	else
		cout << "0\n";
}
// Function that returns size of list
int LinkedList::Size() {
	return size;
}
