#include <iostream>
#include <vector>

bool canMake(const int i, const int current_sum, const int target_sum, const std::vector<int>& nums, std::vector<std::vector<int>>& memo)
{
    if (current_sum == target_sum) return true;
    else if (current_sum > target_sum) return false;
    if (i == nums.size()) return false;

    int& state{ memo[i][current_sum] };

    if (state != -1) return state;

    const bool take{ canMake(i + 1, current_sum + nums[i], target_sum, nums, memo) };
    
    if (take)
    {
        state = take;
        return true;
    }

    const bool skip{ canMake(i + 1, current_sum, target_sum, nums, memo) };

    state = skip;

    return state;
}

bool canPartition(std::vector<int>& nums)
{
    int tot{ 0 };
    for (auto e : nums) tot += e;

    if (tot % 2 != 0) return false;

    const int target{ tot / 2 };

    std::vector<std::vector<int>> memo{ nums.size() + 1, std::vector<int>(target + 1, -1) };

    return canMake(0, 0, target, nums, memo);
}

int main()
{
    std::vector<int> nums1{ 1, 5, 11, 5 };
    std::cout << "Should be true: " << (canPartition(nums1) ? "true" : "false") << "\n";

    std::vector<int> nums2{ 1, 2, 3, 5 };
    std::cout << "Should be false: " << (canPartition(nums2) ? "true" : "false") << "\n";
}