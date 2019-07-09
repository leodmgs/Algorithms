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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        // int nlf = 0;
        // nlf += 1 + countNodes(root->left);
        // return nlf + countNodes(root->right);
        return 1 + countNodes(root->right) + countNodes(root->left);
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

    int ans = s->countNodes(root);

    printf("%d\n", ans);

    return 0;
}
