#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* node, std::vector<int>& ans)
{
    if (!node) return;
    if (node->left) inorder(node->left, ans);
    ans.emplace_back(node->val);
    if (node->right) inorder(node->right, ans);
}

void inorder_iterative(TreeNode* root, std::vector<int>& ans)
{
    std::stack<TreeNode*> stack{ std::stack<TreeNode*>() };
    TreeNode* node{ root };
    while (true)
    {
        if (node != nullptr)
        {
            stack.emplace(node);
            node = node->left;
        }
        else
        {
            if (stack.empty()) return;
            node = stack.top();
            stack.pop();
            ans.emplace_back(node->val);
            node = node->right;
        }
    }
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> ans{ std:: vector<int>() };
    inorder_iterative(root, ans);
    return ans;
}
