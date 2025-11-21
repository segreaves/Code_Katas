#include <iostream>
#include <vector>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool validate(TreeNode* node, const int lower_limit, const int upper_limit)
{
    if (!node) return true;
    if (node->val > lower_limit && node->val < upper_limit)
        return validate(node->left, lower_limit, node->val) && validate(node->right, node->val, upper_limit);
    return false;
}

bool isValidBST(TreeNode* root)
{
    if (!root) return false;
    return validate(root->left, -std::numeric_limits<long int>::max(), root->val) && validate(root->right, root->val, std::numeric_limits<long int>::max());
}

int main()
{
    TreeNode* rll = new TreeNode(0);
    TreeNode* rlr = new TreeNode(2);
    TreeNode* rrl = new TreeNode(4);
    TreeNode* rrr = new TreeNode(6);
    TreeNode* rl = new TreeNode(1, rll, rlr);
    TreeNode* rr = new TreeNode(5, rrl, rrr);
    TreeNode* r = new TreeNode(3, rl, rr);
    std::cout << "Should be true: " << isValidBST(r) << "\n";
}
