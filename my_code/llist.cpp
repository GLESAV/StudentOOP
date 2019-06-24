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
	cout << curr << "\n";
	print_list(os,curr->next);
}

}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head= new Node (d,head);
	

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

bool del_head(Node*& head)
{
		if (head==nullptr)
		{
			return false;
		}
		else if (head->next==nullptr)
		{
			delete head;
			head =nullptr;
			return true;
		}
		else
		{
			Node* delete_this = head;
			head=head->next;
			delete delete_this;
			return true;
		}
		
}
bool del_tail(Node*& head)
{
		if (head==nullptr)
		{
			return false;
		}
		else if (head->next==nullptr)
		{
			delete head;
			head =nullptr;
			return true;
		}
		else{
			del_tail(head->next);
			return true;
		}

}

Node* duplicate(Node* head)
{
	if (head==nullptr)
	{	
		return nullptr;
		
		// Node* new_head= new Node (head->data,duplicate(head->next));
		// return new_head;
	}
	else
	{
		Node* new_tail = new Node(head->data, head->next);
		duplicate(head->next);
		return new_tail;
		;
	}
}

Node* reverse(Node* curr, Node* new_node)
{
	//base case; reaching the end of the current llist;
	if (curr==nullptr)
	{
		Node* new_head = new_node;
		return (new_head);
	}
	else
	{
		Node* new_tail = new Node(curr->data,new_node);
		return reverse(curr->next, new_tail);
	}
}

Node* join(Node*& list1, Node* list2)
{
	if (list1==nullptr && list2==nullptr)
	{
		return nullptr;
	}
	else if (list2==nullptr) // nothing on the back end
	{
		return list1;
	}
	else if (list1==nullptr) // nothing on the front end
	{
		return list2;
	}
	else if (list1->next==nullptr) //the end of list1
	{
		list1->next=list2;
		return list1;
	}
	else 
	{
		join(list1->next, list2);
		return list1;
	}
}



