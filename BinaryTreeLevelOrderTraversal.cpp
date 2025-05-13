#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void goDown(TreeNode* node, int level, std::vector<std::vector<int>>& ans)
{
    if (!node) return;

    if (ans.size() < level + 1) ans.emplace_back(std::vector<int>());

    ans[level].emplace_back(node->val);
    goDown(node->left, level + 1, ans);
    goDown(node->right, level + 1, ans);
}

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> ans;
    goDown(root, 0, ans);
    return ans;
}

int main()
{
}