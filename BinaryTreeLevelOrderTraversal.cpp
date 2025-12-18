#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode* node, int level, std::vector<std::vector<int>>& ans)
{
    if (!node) return;

    if (ans.size() < level + 1) ans.emplace_back(std::vector<int>());

    ans[level].emplace_back(node->val);
    traverse(node->left, level + 1, ans);
    traverse(node->right, level + 1, ans);
}

std::vector<std::vector<int>> traverse_iterative(TreeNode* root)
{
    std::vector<std::vector<int>> ans{ std::vector<std::vector<int>>() };
    if (!root) return ans;
    std::queue<TreeNode*> queue{ std::queue<TreeNode*>() };
    std::vector<int> level{ std::vector<int>() };
    queue.emplace(root);
    while (!queue.empty())
    {
        const auto level_size{ queue.size() };
        std::vector<int> level{ std::vector<int>() };
        for (int i = 0; i < level_size; ++i)
        {
            TreeNode* node{ queue.front() };
            queue.pop();
            level.emplace_back(node->val);
            if (node->left) queue.emplace(node->left);
            if (node->right) queue.emplace(node->right);
        }
        ans.emplace_back(level);
    }
    return ans;
}

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    return traverse_iterative(root);
}

int main()
{
}