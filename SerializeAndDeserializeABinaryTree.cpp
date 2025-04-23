#include <iostream>
#include <string>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serialDFS(TreeNode* node, std::string& s)
{
    if (node == nullptr)
    {
        s.append("#,");
        return;
    }
    s += std::to_string(node->val) + ",";
    serialDFS(node->left, s);
    serialDFS(node->right, s);
    return;
}

// Encodes a tree to a single string.
std::string serialize(TreeNode* root)
{
    std::string ans;
    serialDFS(root, ans);
    return ans;
}

TreeNode* deserialDFS(std::string data, int& i)
{
    std::string val{ "" };
    while (i < data.size() && data[i] != ',') val += data[i++];
    i++;
    if (val == "#") return nullptr;
    TreeNode* node{ new TreeNode(std::stoi(val)) };
    node->left = deserialDFS(data, i);
    node->right = deserialDFS(data, i);
    return node;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(std::string data)
{
    if (data.empty()) return nullptr;
    int i{ 0 };
    return deserialDFS(data, i);
}

int main()
{
    TreeNode* t5{ new TreeNode(5) };
    TreeNode* t4{ new TreeNode(4) };
    TreeNode* t3{ new TreeNode(3) };
    t3->left = t4;
    t3->right = t5;
    TreeNode* t2{ new TreeNode(2) };
    TreeNode* t1{ new TreeNode(1) };
    t1->left = t2;
    t1->right = t3;
    std::string data{ serialize(t1) };
    std::cout << data << std::endl;
    TreeNode* root{ deserialize(data) };
}