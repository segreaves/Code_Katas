#include <iostream>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum)
{
    std::function<bool(TreeNode*, const int, const int)> dfs = [&](TreeNode* node, const int& target, const int sum) {
        if (!node) return false;
        int curr{ sum + node->val };
        if (!node->left && !node->right) return curr == target;
        return dfs(node->left, target, curr) || dfs(node->right, target, curr);
    };

    return dfs(root, targetSum, 0);
}
