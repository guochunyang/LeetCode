#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        
    }
};

