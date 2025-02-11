#include <iostream>
#include <vector>
#include <algorithm>

int missingNumber(std::vector<int>& nums)
{
    // For nums = [0, 1, ..., n] the sum of nums should be n(n-1)/2.
    // If there is a missing number, it must be equal to n(n-1)/2 - sum(nums)
    int n{static_cast<int>(nums.size()) + 1};
    int tot{0};
    for (const auto& i : nums) tot += i;
    return (n * (n - 1) / 2) - tot;
}

int main()
{
    std::vector<int> ex1{3, 0, 1};
    int ans1{missingNumber(ex1)};
    std::cout << "Should be 2: " << ans1 << std::endl;

    std::vector<int> ex2{0, 1};
    int ans2{missingNumber(ex2)};
    std::cout << "Should be 2: " << ans2 << std::endl;

    std::vector<int> ex3{9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans3{missingNumber(ex3)};
    std::cout << "Should be 8: " << ans3 << std::endl;
}