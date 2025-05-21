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

void recursive(TreeNode* node, std::vector<int>& ans)
{
    if (!node) return;

    recursive(node->left, ans);
    recursive(node->right, ans);
    ans.emplace_back(node->val);
}

void iterative(TreeNode* root, std::vector<int>& ans)
{
    if (!root) return;
    
    std::stack<TreeNode*> stack;
    std::stack<TreeNode*> rev_ans;
    stack.push(root);
    while (stack.size() > 0)
    {
        TreeNode* curr{ stack.top() };
        stack.pop();
        rev_ans.push(curr);
        if (curr->left) stack.push(curr->left);
        if (curr->right) stack.push(curr->right);
    }
    while (rev_ans.size() > 0)
    {
        ans.push_back(rev_ans.top()->val);
        rev_ans.pop();
    }
}

std::vector<int> postorderTraversal(TreeNode* root)
{
    std::vector<int> ans;
    iterative(root, ans);
    return ans;
}

void print(const std::vector<int>& arr)
{
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "Ex. 1: " << std::endl;
    TreeNode* t1_7{ new TreeNode(7) };
    TreeNode* t1_15{ new TreeNode(16) };
    TreeNode* t1_20{ new TreeNode(20, t1_15, t1_7) };
    TreeNode* t1_9{ new TreeNode(9) };
    TreeNode* t1_3{ new TreeNode(3, t1_9, t1_20) };
    std::vector<int> ex1{ postorderTraversal(t1_3) };
    print(ex1);
}