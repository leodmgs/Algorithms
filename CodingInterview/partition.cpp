#include <cstdio>
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(NULL) {}
	~Node(){}
};


// Helper method to print the Linked List
void printl(Node *head)
{
	Node *it = head;
	// char i;
	while (it != NULL)
	{
		printf("%d ", it->data);
		// cin >> i;
		it = it->next;
	}
	printf("\n");
}



Node* partition(Node *node, int x)
{
	/* 
		Nodes below are used to keep the reference for the head of each helper list,
		head and tail. The 'head' list hold all nodes lower than 'x' and 'tail' all
		nodes greater or equal than 'x' value.
		The nodes 'head_it' and 'tail_it' are used to pointer to the next value, it
		means the iterator for 'head' and 'tail' lists respectively.
	*/
	Node *head = NULL, *head_it = NULL;
	Node *tail = NULL, *tail_it = NULL;

	while (node != NULL)
	{
		// 'it' holds the next node to be updated at the end of each loop.
		Node *it = node->next;
		if (node->data < x)
		{
			// Once 'head' starts without any value it should be checked.
			if (head != NULL)
			{
				// 'head' already have a value and it only need to be updated.
				head_it->next = node;
				head_it = head_it->next;
			}
			else
			{
				// It is the first time 'head' is being updated.
				head = node;
				head_it = head;
			}
		}
		else
		{
			// 'tail' could be NULL once it starts without any value.
			if (tail != NULL)
			{
				// Update the next value to 'tail' list.
				tail_it->next = node;
				tail_it = tail_it->next;
			}
			else
			{
				// Assign the first value to 'tail' list.
				tail = node;
				tail_it = tail;
			}
		}
		// Update iterator.
		node = it;
	}
	/* 
		After the loop 'tail_it' points for the next node in the regular list.
		In this case, to make sure 'tail' has only value greater than 'x' the
		next value should be nullify.
	*/
	tail_it->next = NULL;

	/*
		'head_it' is the pointer for the last node in 'head' list. In that case,
		to build the entire list the next node should be assined to 'tail' list.
	*/
	head_it->next = tail;

	return head;
}


int main()
{
	Node *head = new Node(11);
	Node *n1 = new Node(5);
	Node *n2 = new Node(8);
	Node *n3 = new Node(3);
	Node *n4 = new Node(10);
	Node *n5 = new Node(2);
	Node *n6 = new Node(1);
	Node *n7 = new Node(-9);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	printf("Input:\n");
	printl(head);
	
	Node* h = partition(head, 6);
	printf("Output:\n");
	printl(h);

	return 0;
}