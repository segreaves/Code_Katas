#include <limits>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* node, int curr_max)
{
    if (!node) return 0;

    int is_good{ 0 };

    if (node->val >= curr_max)
    {
        is_good = 1;
        curr_max = node->val;
    }
    return is_good + dfs(node->left, curr_max) + dfs(node->right, curr_max);
}

int goodNodes(TreeNode* root)
{
    return dfs(root, std::numeric_limits<int>::min());
}

int goodNodesIterative(TreeNode* root)
{
    if (!root) return 0;

    std::vector<std::pair<TreeNode*, int>> stack;
    stack.emplace_back(std::pair<TreeNode*, int>{ root, std::numeric_limits<int>::min() });
    int good_nodes{ 0 };

    while (!stack.empty())
    {
        auto [node, max]{ stack.back() };
        stack.pop_back();

        if (node->val >= max)
        {
            max = node->val;
            ++good_nodes;
        }
        if (node->left) stack.emplace_back(std::pair<TreeNode*, int>{ node->left, max });
        if (node->right) stack.emplace_back(std::pair<TreeNode*, int>{ node->right, max });
    }
    return good_nodes;
}

int main()
{
}