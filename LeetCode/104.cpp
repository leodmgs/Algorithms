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

int maxDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void print_tree(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->val);
	print_tree(root->left);
	print_tree(root->right);
}

int main()
{
	TreeNode* root = new TreeNode(3);
	
	TreeNode* n1 = new TreeNode(9);
	TreeNode* n2 = new TreeNode(20);

	TreeNode* n3 = new TreeNode(15);
	TreeNode* n4 = new TreeNode(7);
	
	TreeNode* n5 = new TreeNode(-1);
	TreeNode* n6 = new TreeNode(2);
	TreeNode* n7 = new TreeNode(3);
	TreeNode* n8 = new TreeNode(6);
	
	n2->left = n3;
	n2->right = n4;
	
	root->left = n1;
	root->right = n2;

	// print_tree(root);
	// printf("\n");

	int ans = maxDepth(root);
	printf("%d\n", ans);

	return 0;
}