//Circular and doubly lists

#include<iostream>
using namespace std;

struct *Node
{
	int info;
	Node *prev;
	Node *next;
};

class linkedList
{
	private:
		Node *head;
		int totalNodes;
}

public:
	{
		Linkedlist ()
		{
			head = NULL;
			totalNodes = 0;
		}
		
		Node createNode(int data)
		{
			Node *newNode = new Node();
			node->prev = NULL;
			node->next = NULL;
			node->info = data; 
		}
		Node insertNode()
	}
