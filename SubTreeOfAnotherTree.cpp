#include <functional>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* a, TreeNode* b)
{
    if (!a && !b) return true;
    else if (!a || !b) return false;
    else if (a->val != b->val) return false;
    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    if (isSameTree(root, subRoot)) return true;
    bool left{ false };
    bool right{ false };
    if (root->left) left = isSubtree(root->left, subRoot);
    if (left) return true;
    if (root->right) right = isSubtree(root->right, subRoot);
    return right;
}

int main()
{
}