#include <iostream>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& numbers, const int& target)
{
    if (numbers.size() < 2) return { -1, -1 };
    size_t l{ 0 };
    size_t r{ numbers.size() - 1 };
    while (l < r)
    {
        auto sum{ numbers[l] + numbers[r] };
        if (sum == target)
            return { static_cast<int>(l + 1), static_cast<int>(r + 1) };
        else if (sum < target) ++l;
        else --r;
    }
    return { -1, -1 };
}

int main()
{
    std::vector<int> ex1{ 2, 7, 11, 15 };
    int target1{ 9 };
    std::vector<int> ans1{ twoSum(ex1, target1) };
    std::cout << "Should be [1, 2]: [" << ans1[0] << ", " << ans1[1] << "]" << std::endl;

    std::vector<int> ex2{ 2, 3, 4 };
    int target2{ 6 };
    std::vector<int> ans2{ twoSum(ex2, target2) };
    std::cout << "Should be [1, 3]: [" << ans2[0] << ", " << ans2[1] << "]" << std::endl;

    std::vector<int> ex3{ -1, 0 };
    int target3{ -1 };
    std::vector<int> ans3{ twoSum(ex3, target3) };
    std::cout << "Should be [1, 2]: [" << ans3[0] << ", " << ans3[1] << "]" << std::endl;
}
