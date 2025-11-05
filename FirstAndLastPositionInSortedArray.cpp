#include <vector>
#include <iostream>

int findFirst(std::vector<int>& nums, int target)
{
    int n = nums.size();
    int start{ 0 };
    int end{ n - 1 };
    while (start <= end)
    {
        int m{ (start + end) / 2 };
        if (nums[m] == target)
        {
            if (m == 0 || nums[m - 1] < target) return m;
            end = m - 1;
        }
        else if (nums[m] < target) start = m + 1;
        else end = m - 1;
    }
    return -1;
}

int findLast(std::vector<int>& nums, int target)
{
    int n = nums.size();
    int start{ 0 };
    int end{ n - 1 };
    while (start <= end)
    {
        int m{ (start + end) / 2 };
        if (nums[m] == target)
        {
            if (m == n - 1 || nums[m + 1] > target) return m;
            start = m + 1;
        }
        else if (nums[m] > target) end = m - 1;
        else start = m + 1;
    }
    return -1;
}

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    int first{ findFirst(nums, target) };
    if (first == -1) return { -1, -1 };
    return { first, findLast(nums, target) };
}

int main()
{
    std::vector<int> ex1{ 5, 7, 7, 8, 8, 10 };
    auto ans1{searchRange(ex1, 8)};
    std::cout << "Should be: [3, 4]: [" << ans1[0] << ", " << ans1[1] << "]" << std::endl;

    std::vector<int> ex2{ 5, 7, 7, 8, 8, 10 };
    auto ans2{searchRange(ex2, 6)};
    std::cout << "Should be: [-1, -1]: [" << ans2[0] << ", " << ans2[1] << "]" << std::endl;

    std::vector<int> ex3{};
    auto ans3{searchRange(ex3, 0)};
    std::cout << "Should be: [-1, -1]: [" << ans3[0] << ", " << ans3[1] << "]" << std::endl;

    std::vector<int> ex4{ 1 };
    auto ans4{searchRange(ex4, 1)};
    std::cout << "Should be: [0, 0]: [" << ans4[0] << ", " << ans4[1] << "]" << std::endl;
}