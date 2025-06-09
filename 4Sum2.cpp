#include <iostream>
#include <vector>
#include <unordered_map>

int bruteForce(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
{
    int tot{ 0 };
    for (const auto& n1 : nums1)
        for (const auto& n2 : nums2)
            for (const auto& n3 : nums3)
                for (const auto& n4 : nums4)
                    tot = (n1 + n2 + n3 + n4) ? tot : tot + 1;

    return tot;
}

int optimized(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
{
    std::unordered_map<int, int> m;
    // Records sums from nums1 and nums2
    for (const auto& n1 : nums1)
        for (const auto& n2 : nums2)
            m[n1 + n2]++;

    int ans{ 0 };
    // Pairs found in memory (but negative) meet the requirements
    for (const auto& n3 : nums3)
        for (const auto& n4 : nums4)
            if (m.find(-(n3 + n4)) != m.end()) ans += m[-(n3 + n4)];

    return ans;
}

int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
{
    return optimized(nums1, nums2, nums3, nums4);
}

int main()
{
    std::vector nums1{ 1, 2 };
    std::vector nums2{ -2, -1 };
    std::vector nums3{ -1, 2 };
    std::vector nums4{ 0, 2 };
    std::cout << "Should be 2: " << fourSumCount(nums1, nums2, nums3, nums4) << std::endl;
}