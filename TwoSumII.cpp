#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    int l{ 0 };
    int r{ static_cast<int>(numbers.size()) - 1 };
    while (l < r)
    {
        if (numbers[l] + numbers[r] == target) return {++l, ++r};
        if (numbers[l] + numbers[r] < target) l++;
        else r--;
    }
    return {-1, -1};
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