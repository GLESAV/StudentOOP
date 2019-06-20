#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {

		os << nd->data << "\t";
	
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	//cout << "Function is called";
	if(head==nullptr)
	{
		head= new Node(d);
	}
	else
	{
		add_at_end(head->next,d);
	}
	
	
	
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
if (curr==nullptr)
{
	return;
}
else{
	cout << curr << "\t";
	print_list(os,curr->next);
}

}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head= new Node (d,head->next);
	

}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (head==nullptr)
	{return nullptr;}
else if (head->next==nullptr)
{
	return head;
}
else{
	return last(head->next);
}

}
