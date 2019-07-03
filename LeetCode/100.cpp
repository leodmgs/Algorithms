#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if (p == NULL and q == NULL)
		return true;

	if (p != NULL and q != NULL)
	{
		if (p->val == q->val) {
			bool eql = isSameTree(p->left, q->left);
			bool rql = isSameTree(p->right, q->right);
			return (eql and rql);
		}
		else
		{
			return false;
		}
	}
	return false;
}

void print_tree(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%d\n", root->val);
	print_tree(root->left);
	print_tree(root->right);
}

int main()
{
	TreeNode* root1 = new TreeNode(0);
	TreeNode* n1 = new TreeNode(-8);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(4);
	
	n1->left = n3;
	n2->right = n4;
	
	root1->left = n1;
	root1->right = n2;
	
	TreeNode* root2 = new TreeNode(0);
	TreeNode* n5 = new TreeNode(-8);
	TreeNode* n6 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(4);
	TreeNode* n8 = new TreeNode(4);
	
	n5->left = n7;
	n6->right = n8;

	root2->left = n5;
	root2->right = n6;

	bool ans = isSameTree(root1, root2);
	printf(ans ? "true\n" : "false\n");

	return 0;
}