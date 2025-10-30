#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> subsets(std::vector<int>& nums)
{
    std::vector<std::vector<int>> ans;
    // Number of subsets is nums.size() squared
    ans.reserve(std::pow(2, nums.size()));
    ans.emplace_back(std::vector<int>());
    for (const auto& e : nums)
    {
        auto temp{ ans };
        for (auto& set : temp) set.emplace_back(e);
        ans.insert(ans.begin(), temp.begin(), temp.end());
    }
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
    std::vector<std::vector<int>> ans1{ subsets(ex1) };
    printSet(ans1);
}