#include <iostream>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum)
{
    std::vector<std::vector<int>> res{};
    std::vector<int> path;

    std::function<void(TreeNode*, int, const int)> func =
        [&](TreeNode* node, int prevSum, const int targetSum) {
            if (!node) return;

            int curr{ prevSum + node->val };
            path.push_back(node->val);
            if (!node->left && !node->right && curr == targetSum)
            {
                std::vector<int> resPath;
                for (auto i : path) resPath.emplace_back(i);
                res.emplace_back(path);
            }
            func(node->left, curr, targetSum);
            func(node->right, curr, targetSum);
            path.pop_back();
        };

    func(root, 0, targetSum);
    return res;
}

int main()
{
}