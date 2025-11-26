#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return nullptr;
    if (root->val == p->val || root->val == q->val) return root;

    TreeNode* l{ lowestCommonAncestor(root->left, p, q) };
    TreeNode* r{ lowestCommonAncestor(root->right, p, q) };
    if (!l && !r) return nullptr;
    if (l && r) return root;
    return l ? l : r;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return nullptr;
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root) return nullptr;
    while (true)
    {
        if (root->val > p->val && root->val > q->val) root = root->left;
        else if (root->val < p->val && root->val < q->val) root = root->right;
        else return root;
    }
}

int main()
{
}