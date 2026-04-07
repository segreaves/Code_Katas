#include <iostream>
#include <queue>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root)
{
    // Level order traversal of binary tree
    std::queue<TreeNode*> q;
    q.emplace(root);
    int max_level{ 0 };
    int curr_level{ 0 };
    int max_level_val{ std::numeric_limits<int>::min() };
    while(!q.empty())
    {
        curr_level++;
        // Initialize the level count
        int level_count{ 0 };
        // Get the size of the level
        const size_t level_size{ q.size() };
        // Loop through the level
        for (int i = 0; i < level_size; ++i)
        {
            TreeNode* node{ q.front() };
            q.pop();
            // Add value to the level count
            level_count += node->val;
            // Put children of nodes in queue
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        if (level_count > max_level_val)
        {
            max_level_val = level_count;
            max_level = curr_level;
        }
    }
    return max_level;
}

int main()
{
}