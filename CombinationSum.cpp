#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& candidates, const int target, std::vector<int> curr, const int index, int sum, std::vector<std::vector<int>>& ans)
{
    if (sum == target) ans.emplace_back(curr);
    else if (sum < target)
    {
        for (int i = index; i < candidates.size(); ++i)
        {
            int val{ candidates[i] };
            curr.emplace_back(val);
            backtrack(candidates, target, curr, i, val + sum, ans);
            curr.pop_back();
        }
    }
    return;
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int>> ans;
    ans.reserve(150);
    std::vector<int> curr;
    curr.reserve(candidates.size());
    backtrack(candidates, target, curr, 0, 0, ans);
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
