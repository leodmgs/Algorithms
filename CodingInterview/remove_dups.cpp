#include <cstdio>
#include <unordered_set>

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(NULL) {}
};

using namespace std;

// Helper method to print the Linked List
void printl(Node *head)
{
	Node *it = head;
	while (it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

// Solution: time = O(n), space = O(n).
void remove_dups(Node *node)
{
	// Set to store unique data and check if a data already exist.
	unordered_set<int> data_set;

	// Node to hold a reference for the last unique node.
	Node *prev;

	// Loop through the linked list using the object node for the iteration.
	while (node != NULL)
	{
		// Check if it is a unique value from the Set data structure
		if (data_set.find(node->data) == data_set.end())
		{
			data_set.insert(node->data);
			// Once it is unique, the reference for the previous node is updated
			prev = node;
		}
		else
		{
			// The reference for the previous node is still the same and as
			// current node is duplicated, the reference for the next from
			// previous - currently holding the last unique data - is updated.
			prev->next = node->next;
		}
		// Iterator for each node in Linked List.
		node = node->next;
	}
}

// FOLLOW UP
// Solution: time = O(n^2), space = O(1) ?
void remove_dups(Node *node)
{
	// TODO
}

int main()
{
	Node *head = new Node(1);
	Node *n1 = new Node(5);
	Node *n2 = new Node(2);
	Node *n3 = new Node(1);
	Node *n4 = new Node(2);
	Node *n5 = new Node(5);
	Node *n6 = new Node(3);
	Node *n7 = new Node(9);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	remove_dups(head);
	printl(head);

	return 0;
}