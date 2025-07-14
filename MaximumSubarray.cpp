#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums)
{
    int max_sum{ nums[0] };
    int curr_sum{ max_sum };
    const size_t n{ nums.size() };
    for (size_t i = 1; i < n; ++i)
    {
        curr_sum = std::max(nums[i], curr_sum + nums[i]);
        max_sum = std::max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    std::vector<int> nums1{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int ans1{ maxSubArray(nums1) };
    std::cout << "Should be 6: " << ans1 << "\n";

    std::vector<int> nums2{ 1 };
    int ans2{ maxSubArray(nums2) };
    std::cout << "Should be 1: " << ans2 << "\n";

    std::vector<int> nums3{ 5, 4, -1, 7, 8 };
    int ans3{ maxSubArray(nums3) };
    std::cout << "Should be 23: " << ans3 << "\n";

    std::vector<int> nums4{ -3, -1, -8 };
    int ans4{ maxSubArray(nums4) };
    std::cout << "Should be -1: " << ans4 << "\n";
}
