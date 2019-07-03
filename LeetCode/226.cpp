#include <cstdio>
#include <unordered_map>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* invertTree(TreeNode* root)
{
	if (root == NULL)
		return root;

	TreeNode* node_temp = root->left;
	root->left = root->right;
	root->right = node_temp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
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
	TreeNode* root = new TreeNode(4);
	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(7);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(6);
	TreeNode* n6 = new TreeNode(9);
	TreeNode* n7 = new TreeNode(5);

	n1->left = n3;
	n1->right = n4;

	n2->left = n5;
	n2->right = n6;

	n3->left = n7;

	root->left = n1;
	root->right = n2;

	TreeNode* ans_node = invertTree(root);
	print_tree(ans_node);

	return 0;
}