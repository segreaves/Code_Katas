#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPath(TreeNode* node, int curr)
{
    if (node->left && node->right) return hasPath(node->left, curr - node->val) || hasPath(node->right, curr - node->val);
    else if (node->left && !node->right) return hasPath(node->left, curr - node->val);
    else if (!node->left && node->right) return hasPath(node->right, curr - node->val);
    return node->val == curr;
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if (!root) return false;
    return hasPath(root, targetSum);
}
