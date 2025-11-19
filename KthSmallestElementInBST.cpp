#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findKthSmallestElem(TreeNode* node, int& k, int& ans)
{
    if (!node) return;
    findKthSmallestElem(node->left, k, ans);
    if (--k == 0)
    {
        ans = node->val;
        return;
    }
    findKthSmallestElem(node->right, k, ans);
}

int kthSmallest(TreeNode* root, int k)
{
    int ans;
    findKthSmallestElem(root, k, ans);
    return ans;
}
