#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> subsets1(std::vector<int>& nums)
{
    std::vector<std::vector<int>> ans;
    ans.reserve(pow(2, nums.size()));
    ans.emplace_back(std::vector<int>());
    for (const auto& e : nums)
    {
        auto temp{ ans };
        for (auto& set : temp) set.push_back(e);
        ans.insert(ans.end(), temp.begin(), temp.end());

    }
    return ans;
}

void solution(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& curr, int index)
{
    if (index > nums.size()) return;
    ans.push_back(curr);
    for (int i = index; i < nums.size(); i++)
    {
        if (find(curr.begin(), curr.end(), nums[i]) == curr.end())
        {
            curr.push_back(nums[i]);
            solution(nums, ans, curr, i);
            curr.pop_back();
        }
    }
    return;
}

std::vector<std::vector<int>> subsets2(std::vector<int>& nums)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> curr;
    solution(nums, ans, curr, 0);
    return ans;
}

void printSet(std::vector<std::vector<int>> set)
{
    for (const auto& e : set)
    {
        std::cout << "[";
        for (int i = 0; i < e.size(); i++)
        {
            std::cout << e[i];
            if (i < e.size() - 1) std::cout << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ex1{ 1, 2, 3 };
    std::vector<std::vector<int>> ans1{ subsets1(ex1) };
    printSet(ans1);

    std::vector<std::vector<int>> ans2{ subsets2(ex1) };
    printSet(ans2);
}