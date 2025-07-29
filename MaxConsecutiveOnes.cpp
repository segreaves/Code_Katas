#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
    // nums.size() guaranteed to be >= 1
    int max_ones{ 0 };
    int curr_ones{ 0 };
    for (const auto& num : nums)
    {
        if (num) max_ones = std::max(max_ones, ++curr_ones);
        else curr_ones = 0;
    }
    return max_ones;
}

int main()
{
    std::vector<int> ex1{ 1, 1, 0, 1, 1, 1 };
    std::cout << "Should be 3: " << findMaxConsecutiveOnes(ex1) << "\n";

    std::vector<int> ex2{ 1, 0, 1, 1, 0, 1 };
    std::cout << "Should be 2: " << findMaxConsecutiveOnes(ex2) << "\n";
}