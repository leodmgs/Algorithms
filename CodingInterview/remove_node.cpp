#include <cstdio>

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
	while (it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

bool delete_node(Node *node)
{
	if (node == NULL or node->next == NULL)
		return false;
	node->data = node->next->data;
	node->next = node->next->next;
	return true;
}

int main()
{
	Node *head = new Node(1);
	Node *n1 = new Node(2);
	Node *n2 = new Node(3);
	Node *n3 = new Node(4);
	Node *n4 = new Node(5);
	Node *n5 = new Node(6);
	Node *n6 = new Node(7);
	Node *n7 = new Node(8);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	printl(head);
	bool ans = delete_node(n4);
	if (ans) printl(head);
	else printf("[error] Can't remove node.\n");

	return 0;
}