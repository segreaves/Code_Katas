#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root)
{
    if (root ==  nullptr) return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    std::cout << "Ex. 1: " << std::endl;
    TreeNode* t1_7{ new TreeNode(7) };
    TreeNode* t1_15{ new TreeNode(16) };
    TreeNode* t1_20{ new TreeNode(20, t1_15, t1_7) };
    TreeNode* t1_9{ new TreeNode(9) };
    TreeNode* t1_3{ new TreeNode(3, t1_9, t1_20) };
    std::cout << "Should be 3: " << maxDepth(t1_3) << std::endl;

    std::cout << "Ex. 2: " << std::endl;
    TreeNode* t2_2{ new TreeNode(2) };
    TreeNode* t2_1{ new TreeNode(1, nullptr, t2_2) };
    std::cout << "Should be 2: " << maxDepth(t2_1) << std::endl;
}