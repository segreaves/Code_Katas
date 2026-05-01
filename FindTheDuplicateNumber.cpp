#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& nums)
{
    int n = nums.size() - 1; // nums has n+1 elements, values in [1, n]
    int duplicate = 0;

    for (int bit = 0; (1 << bit) <= n; ++bit)
    {
        int mask{ 1 << bit };
        int count_nums{ 0 };
        int count_range{ 0 };
        for (int i = 0; i <= n; ++i)
        {
            count_nums += (nums[i] & mask) > 0;
            count_range += (i > 0 && i & mask) > 0;
        }
        duplicate = count_nums > count_range ? duplicate |= mask : duplicate;
    }

    return duplicate;
}

int main()
{
    std::vector<int> nums1 = {1, 3, 4, 2, 2};
    std::vector<int> nums2 = {3, 1, 3, 4, 2};
    std::vector<int> nums3 = {3, 3, 3, 3, 3};

    std::cout << findDuplicate(nums1) << "\n"; // 2
    std::cout << findDuplicate(nums2) << "\n"; // 3
    std::cout << findDuplicate(nums3) << "\n"; // 3
}