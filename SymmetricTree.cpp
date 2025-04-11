#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isMirror(TreeNode* l, TreeNode* r)
{
    if (l == nullptr && r == nullptr) return true;// Both are null
    if (l == nullptr || r == nullptr) return false;// One is null and other isn't
    return (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root)
{
    if (root == nullptr) return false;
    return isMirror(root->left, root->right);
}

int main()
{
    std::cout << "Ex. 1: " << std::endl;
    TreeNode* t1l_l{ new TreeNode(3) };
    TreeNode* t1l_r{ new TreeNode(4) };
    TreeNode* t1r_l{ new TreeNode(4) };
    TreeNode* t1r_r{ new TreeNode(3) };
    TreeNode* t1_l{ new TreeNode(2, t1l_l, t1l_r) };
    TreeNode* t1_r{ new TreeNode(2, t1r_l, t1r_r) };
    TreeNode* t1{ new TreeNode(1, t1_l, t1_r) };
    std::cout << "Should be 1: " << isSymmetric(t1) << std::endl;

    std::cout << "Ex. 2: " << std::endl;
    TreeNode* t2l_r{ new TreeNode(3) };
    TreeNode* t2r_r{ new TreeNode(3) };
    TreeNode* t2_l{ new TreeNode(2, nullptr, t2l_r) };
    TreeNode* t2_r{ new TreeNode(2, nullptr, t2r_r) };
    TreeNode* t2{ new TreeNode(1, t2_l, t2_r) };
    std::cout << "Should be 0: " << isSymmetric(t2) << std::endl;

    std::cout << "Ex. 3: " << std::endl;
    TreeNode* t3l{ new TreeNode(2) };
    TreeNode* t3r{ new TreeNode(3) };
    TreeNode* t3{ new TreeNode(1, t3l, t3r) };
    std::cout << "Should be 0: " << isSymmetric(t3) << std::endl;
}