#include <cstdio>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
		Success
		Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
		Memory Usage: 13.5 MB, less than 57.58% of C++ online submissions for Sum of Left Leaves.
	 */
    int sumOfLeftLeaves(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	int t = 0;
    	if (root->left != NULL)
    		if (root->left->left == NULL and root->left->right == NULL)
    			t = root->left->val;
    	return t + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }	
};

int main()
{
	Solution* s = new Solution();
	
	// TreeNode* n3 = new TreeNode(15);
	// TreeNode* n4 = new TreeNode(7);

	// TreeNode* n2 = new TreeNode(20);
	// n2->left = n3;
	// n2->right = n4;

	// TreeNode* n1 = new TreeNode(9);

	// TreeNode* root = new TreeNode(3);
	// root->left = n1;
	// root->right = n2;

	// TreeNode* root = new TreeNode(1);

	TreeNode* root = new TreeNode(3);
	TreeNode* n1 = new TreeNode(9);
	TreeNode* n2 = new TreeNode(20);
	TreeNode* n3 = new TreeNode(15);
	TreeNode* n4 = new TreeNode(100);
	TreeNode* n5 = new TreeNode(7);
	TreeNode* n6 = new TreeNode(200);
	TreeNode* n7 = new TreeNode(1);

	root->left = n1;
	root->right = n2;

	n2->left = n3;
	n2->right = n4;
	
	n4->left = n5;
	n4->right = n6;

	n6->left = n7;

	int ans = s->sumOfLeftLeaves(root);
	printf("%d\n", ans);
	return 0;
}