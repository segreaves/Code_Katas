#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        int remainder{ target - nums[i] };
        if (m.find(remainder) != m.end()) return { m[remainder], i };
        else m[nums[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    std::vector<int> ex1{ 2, 7, 11, 15 };
    int target1{ 9 };
    const auto& ans1 { twoSum(ex1, target1) };
    std::cout << "Should be [0, 1]: [" << ans1[0] << ", " << ans1[1] << "]" << std::endl;

    std::vector<int> ex2{ 3, 2, 4 };
    int target2{ 6 };
    const auto& ans2 { twoSum(ex2, target2) };
    std::cout << "Should be [1, 2]: [" << ans2[0] << ", " << ans2[1] << "]" << std::endl;

    std::vector<int> ex3{ 3, 3 };
    int target3{ 6 };
    const auto& ans3 { twoSum(ex3, target3) };
    std::cout << "Should be [0, 1]: [" << ans3[0] << ", " << ans3[1] << "]" << std::endl;
}