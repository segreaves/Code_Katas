#include <iostream>
#include <cmath>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPath(TreeNode* node, int& ans)
{
    if (!node) return 0;

    int l{ maxPath(node->left, ans) };
    int r{ maxPath(node->right, ans) };

    int maxSide{ std::max(node->val, node->val + std::max(l, r)) };
    int maxCurrent{ std::max(maxSide, node->val + l + r) };

    ans = std::max(ans, maxCurrent);
    return maxSide;
}

int maxPathSum(TreeNode* root)
{
    int ans{ -std::numeric_limits<int>::max() };
    maxPath(root, ans);
    return ans;
}

int main()
{
    //
}