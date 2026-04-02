#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCousins(TreeNode* root, int x, int y)
{
    if (!root) return false;

    std::queue<std::pair<TreeNode*, int>> nodes;
    nodes.push(std::pair<TreeNode*, int>(root, root->val));

    while (!nodes.empty())
    {
        size_t level_size{ nodes.size() };
        int parent_x{ 0 };
        int parent_y{ 0 };

        for (int i = 0; i < level_size; ++i)
        {
            auto curr_pair{ nodes.front() };
            TreeNode* node{ curr_pair.first };
            int parent_val{ curr_pair.second };
            nodes.pop();
            if (node->val == x) parent_x = parent_val;
            else if (node->val == y) parent_y = parent_val;
            if (parent_x && parent_y) return parent_x != parent_y;
            if (node->left) nodes.push(std::pair<TreeNode*, int>(node->left, node->val));
            if (node->right) nodes.push(std::pair<TreeNode*, int>(node->right, node->val));
        }
        if (parent_x != parent_y) return false;
    }
    return false;
}

int main()
{
}