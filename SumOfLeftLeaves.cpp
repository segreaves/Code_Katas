#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode* root)
{
    auto dfs = [&](TreeNode* node, bool is_left, const auto& self) -> int {
        if (!node) return 0;
        int left{ self(node->left, true, self) };
        int right{ self(node->right, false, self) };
        if (!node->left && !node->right) return is_left ? node->val : 0;
        return left + right;
    };
    return dfs(root, false, dfs);
}

int main()
{
}