#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> levelOrderTraversal(TreeNode* root)
{
    std::vector<int> res{};

    if (!root) return res;

    std::queue<TreeNode*> queue;
    queue.emplace(root);
    int level{ 0 };

    while (!queue.empty())
    {
        auto level_size{ queue.size() };
        for (int i = 0; i < level_size; ++i)
        {
            TreeNode* node{ queue.front() };
            queue.pop();
            if (res.size() == level) res.push_back(node->val);
            if (node->right) queue.emplace(node->right);
            if (node->left) queue.emplace(node->left);
        }
        ++level;
    }

    return res;
}

std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> res{};

    auto traverse = [&](TreeNode* node, int depth, const auto& self) {
        if (!node) return;

        if (res.size() == depth) res.emplace_back(node->val);

        if (node->right) self(node->right, depth + 1, self);
        if (node->left) self(node->left, depth + 1, self);
        return;
    };

    traverse(root, 0, traverse);
    return res;
}

int main()
{
}
