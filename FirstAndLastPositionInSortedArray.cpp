#include <vector>
#include <iostream>

int findFirst(std::vector<int>& nums, int target)
{
    int l{0};
    int r{static_cast<int>(nums.size()) - 1};
    while (l <= r)
    {
        int m{static_cast<int>((l + r) / 2)};
        if (nums[m] == target)
        {
            if (m == 0 || nums[m - 1] < target) { return m; }
            r = m - 1;
        }
        else if (nums[m] > target) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int findLast(std::vector<int>& nums, int target, int start_l)
{
    int l{start_l};
    int r{static_cast<int>(nums.size()) - 1};
    while (l <= r)
    {
        int m{static_cast<int>((l + r) / 2)};
        if (nums[m] == target)
        {
            if (m == nums.size() - 1 || nums[m + 1] > target) { return m; }
            l = m + 1;
        }
        else if (nums[m] > target) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    int first{findFirst(nums, target)};
    if (first == -1) { return std::vector<int>({-1, -1});}
    return std::vector({first, findLast(nums, target, first)});
}

int main()
{
    std::vector<int> ex1{5, 7, 7, 8, 8, 10};
    int target1{8};
    auto ans1{searchRange(ex1, target1)};
    std::cout << "Should be: [3, 4]: [" << ans1[0] << ", " << ans1[1] << "]" << std::endl;

    std::vector<int> ex2{5, 7, 7, 8, 8, 10};
    int target2{6};
    auto ans2{searchRange(ex2, target2)};
    std::cout << "Should be: [-1, -1]: [" << ans2[0] << ", " << ans2[1] << "]" << std::endl;

    std::vector<int> ex3{};
    int target3{0};
    auto ans3{searchRange(ex3, target3)};
    std::cout << "Should be: [-1, -1]: [" << ans3[0] << ", " << ans3[1] << "]" << std::endl;
}