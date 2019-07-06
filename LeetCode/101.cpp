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
		Runtime: 4 ms, faster than 90.27% of C++ online submissions for Symmetric Tree.
		Memory Usage: 14.6 MB, less than 82.39% of C++ online submissions for Symmetric Tree.
	 */
	bool isSymmetric(TreeNode* preNode, TreeNode* posNode)
	{
		if (preNode == NULL and posNode == NULL)
			return true;
		else if ((preNode == NULL and posNode != NULL) or 
			((preNode != NULL and posNode == NULL)))
			return false;
		bool preResult = isSymmetric(preNode->left, posNode->right);
		bool posResult = isSymmetric(preNode->right, posNode->left);
		if (preNode->val != posNode->val)
			return false;
		return (preResult and posResult);
	}

    bool isSymmetric(TreeNode* root) 
    {
    	return isSymmetric(root, root);
    }
};

int main()
{
	Solution* s = new Solution();

	TreeNode* root = new TreeNode(1);
	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(4);
	TreeNode* n6 = new TreeNode(3);
	TreeNode* n7 = new TreeNode(5);
	TreeNode* n8 = new TreeNode(6);
	TreeNode* n9 = new TreeNode(7);
	TreeNode* n10 = new TreeNode(8);
	TreeNode* n11 = new TreeNode(8);
	TreeNode* n12 = new TreeNode(7);
	TreeNode* n13 = new TreeNode(6);
	TreeNode* n14 = new TreeNode(5);

	root->left = n1;
	root->right = n2;

	n1->left = n3;
	n1->right = n4;
	
	n2->left = n5;
	n2->right = n6;

	n3->left = n7;
	n3->right = n8;

	n4->left = n9;
	n4->right = n10;

	n5->left = n11;
	n5->right = n12;

	n6->left = n13;
	n6->right = n14;

	bool ans = s->isSymmetric(root);

	printf(ans ? "True\n" : "False\n");
	return 0;
}