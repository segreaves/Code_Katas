#include <limits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* node, int curr_max, int& res)
{
    if (!node) return;

    if (node->val >= curr_max)
    {
        ++res;
        curr_max = node->val;
    }
    dfs(node->left, curr_max, res);
    dfs(node->right, curr_max, res);
    return;
}

int goodNodes(TreeNode* root)
{
    int res{ 0 };
    dfs(root, std::numeric_limits<int>::min(), res);
    return res;
}

int main()
{
}