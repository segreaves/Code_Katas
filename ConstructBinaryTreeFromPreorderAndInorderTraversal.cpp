#include <vector>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* buildTree(std::vector<int>& preorder, int& pre_start,
                    std::vector<int>& inorder, int in_start, int in_end)
{
    if (in_start > in_end) return nullptr;

    TreeNode* node = new TreeNode(preorder[pre_start++]);
    auto it{ std::find(inorder.begin() + in_start, inorder.begin() + in_end + 1, node->val) };
    int index{ static_cast<int>(std::distance(inorder.begin(), it)) };
    // Build left tree
    node->left = buildTree(preorder, pre_start, inorder, in_start, index - 1);
    // Build right tree
    node->right = buildTree(preorder, pre_start, inorder, index + 1, in_end);
    return node;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    if (preorder.empty() || inorder.empty()) return nullptr;

    int start{ 0 };
    return buildTree(preorder, start, inorder, 0, inorder.size() - 1);
}

int main()
{
}