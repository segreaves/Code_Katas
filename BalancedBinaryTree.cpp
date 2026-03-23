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

bool isBalanced(TreeNode* root)
{
    std::function<int(TreeNode*)> height = [&](TreeNode* node) {
        if (!node) return 0;
        int left{ height(node->left) };
        int right{ height(node->right) };
        if (left == -1 || right == -1 || std::abs(left - right) > 1) return -1;
        return std::max(left, right) + 1;
    };

    return height(root) != -1;
}

int main()
{
}