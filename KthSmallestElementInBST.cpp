#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solution(TreeNode* node, int& k, int& ans)
{
    if (node == nullptr) return;
    solution(node->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = node->val;
        return;
    }
    solution(node->right, k, ans);
}

int kthSmallest(TreeNode* root, int k)
{
    int ans;
    solution(root, k, ans);
    return ans;
}
