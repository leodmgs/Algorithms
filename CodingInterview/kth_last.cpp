#include <cstdio>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(NULL) {}
};

// Solution: O(n)
Node* kth_to_last(Node *node, int kth)
{
	// Holds the kth to last, the left adjacent Node.
	Node *node_kth = node;
	// Counter to indicate when node_kth Node must to start iterating
	int counter = 0;
	// Iterator from the beginning to the last Node
	Node *it = node;
	while (it != NULL)
	{
		it = it->next;
		// If counter is greater than 'kth', node_kth must to iterating
		// to follow the iterator holding the kth distance.
		if (counter > kth)
			node_kth = node_kth->next;
		++counter;
	}
	// As counter contains the size of the list, if kth is greater than it,
	// returns NULL indicating that it is invalid, or the node_kth otherwise.
	return kth < counter ? node_kth : NULL;
}

int main()
{
	Node *head = new Node(1);
	Node *n1 = new Node(5);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(7);
	Node *n5 = new Node(8);
	Node *n6 = new Node(4);
	Node *n7 = new Node(9);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	Node *ans = kth_to_last(head, 5);
	if (ans != NULL)
		printf("%d\n", ans->data);
	else
		printf("[error]: kth is greater than list size.\n");

	return 0;
}