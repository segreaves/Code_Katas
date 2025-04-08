#include <iostream>
#include <vector>

void explore(const std::vector<int>& candidates, std::vector<std::vector<int>>& ans, std::vector<int> curr, const int target, int index, int sum)
{
    if (sum == target) ans.push_back(curr);
    else if (sum < target)
    {
        for (int i = index; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            explore(candidates, ans, curr, target, i, sum + candidates[i]);
            curr.pop_back();
        }
    }
    return;
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> curr;
    explore(candidates, ans, curr, target, 0, 0);
    return ans;
}

void printArrays(std::vector<std::vector<int>> arr)
{
    std::cout << "[";
    for (const auto& subArr : arr)
    {
        std::cout << "[";
        for (const auto& e : subArr) std::cout << e << " ";
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> candidates1{ 2, 3, 6, 7 };
    int target1{ 7 };
    std::cout << "Should be [[2,2,3],[7]]: " << std::endl;
    printArrays(combinationSum(candidates1, target1));
}