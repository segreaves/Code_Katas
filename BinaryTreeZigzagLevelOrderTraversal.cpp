#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode*> q;
    q.emplace(root);
    int index{ 1 };
    while (q.size() > 0)
    {
        int q_len{ static_cast<int>(q.size()) };
        std::vector<int> level;
        for (int i = 0; i < q_len; i++)
        {
            TreeNode* node{ q.front() };
            q.pop();

            level.push_back(node->val);
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        if (index % 2 == 0) std::reverse(level.begin(), level.end());
        ans.push_back(level);
        index++;
    }
    return ans;
}

int main()
{
    
}