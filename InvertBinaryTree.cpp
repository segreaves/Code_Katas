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

TreeNode* invertTree(TreeNode* root)
{
    std::function<TreeNode*(TreeNode*)> invert = [&](TreeNode* node) {
        if (!node) return node;
        TreeNode* left{ invert(node->right) };
        TreeNode* right{ invert(node->left) };
        std::swap(node->left, node->right);
        return node;
    };

    return invert(root);
}

int main()
{
}