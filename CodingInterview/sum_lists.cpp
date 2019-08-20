#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int d) : data(d), next(NULL) {}
	~Node(){}
};


/*
	Receives a number represented by a linked list in the right order
	and returns it as an integer. For example, from the list 5 -> 9 -> 2 
	the function below will return the integer 592.
 */
int get_number_pre_order(Node *n)
{
	// Stack data structure is used in order to know all the numbers
	stack<int> nstack;
	while (n != NULL)
	{
		nstack.push(n->data);
		n = n->next;
	}
	int number = 0;
	int factor = 1;
	while (!nstack.empty())
	{
		// Once the stack is FILO the numbers can be read in the right
		// order to use the factor and get the right sum of each part
		// of the final number.
		number += nstack.top() * factor;
		factor *= 10;
		nstack.pop();
	}
	return number;
}


/*
	Receive a number represented by a linked list where the numbers are
	in a reverse order and returns an integer in the right order of the
	digits. For example, from the list 5 -> 9 -> 2, the function below
	will return the integer 295.
 */
int get_number_pos_order(Node *n)
{
	int number = 0;
	int factor = 1;
	while (n != NULL)
	{
		// Since the first number is the least significant, the factor 
		// increases according to the regular position of each number.
		number += n->data * factor;
		factor *= 10;
		n = n->next;
	}
	return number;
}


/*
	Sums two numbers represented by a linked list, where each number is
	organized in the list in right order. For example, assuming two lists
	`L1 = 5 -> 9 -> 2` and `L2 = 1 -> 4 -> 3` the result should be the
	integer 735.
 */
int sum_lists_pre(Node *n1, Node *n2)
{
	int number1 = n1 != NULL ? get_number_pre_order(n1) : 0;
	int number2 = n2 != NULL ? get_number_pre_order(n2) : 0;
	return number1 + number2;
}


/*
	Sums two number represented by a linked list, where the numbers
	are in a reverse order. Considering an example, for the lists
	`L1 = 5 -> 9 -> 2` and `L2 = 1 -> 4 -> 3` the function will return
	the integer 636.
 */
int sum_lists_pos(Node *n1, Node *n2)
{
	int number1 = n1 != NULL ? get_number_pos_order(n1) : 0;
	int number2 = n2 != NULL ? get_number_pos_order(n2) : 0;
	return number1 + number2;
}


int main()
{
	// Linked list to represent the first number
	Node *n1_1 = new Node(1);
	Node *n1_2 = new Node(1);
	Node *n1_3 = new Node(6);
	Node *n1_4 = new Node(9);
	n1_1->next = n1_2;
	n1_2->next = n1_3;
	n1_3->next = n1_4;

	// Linked list to represent the second number
	Node *n2_1 = new Node(5);
	Node *n2_2 = new Node(9);
	Node *n2_3 = new Node(2);	
	n2_1->next = n2_2;
	n2_2->next = n2_3;

	int ans = sum_lists_pre(n1_1, n2_1);
	printf("pre-order: %d\n", ans);

	ans = sum_lists_pos(n1_1, n2_1);
	printf("pos-order: %d\n", ans);

	return 0;
}
