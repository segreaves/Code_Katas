#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameterOfBinaryTree(TreeNode* root)
{
    int diameter{ 0 };

    auto dfs = [&](TreeNode* node, auto& dfs_ref) -> int {
        if (!node) return 0;
        int left = dfs_ref(node->left, dfs_ref);
        int right = dfs_ref(node->right , dfs_ref);
        diameter = std::max(diameter, left + right);
        return 1 + std::max(left, right);
    };

    dfs(root, dfs);
    return diameter;
}

int main()
{
}