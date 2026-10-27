#include <iostream>
#include <vector>

int rob(std::vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());

    if (n == 0) return 0;

    int two_back{ 0 };
    int one_back{ 0 };

    for (int money : nums)
    {
        int curr = std::max(
            two_back + money,// rob
            one_back// skip
        );
        two_back = one_back;
        one_back = curr;
    }

    return one_back;
}

int main()
{
    std::vector<int> ex1{ 1, 2, 3, 1 };
    int ans_1{ rob(ex1) };
    std::cout << "Should be 4: " << ans_1 << std::endl;

    std::vector<int> ex2{ 2, 7, 9, 3, 1 };
    int ans_2{ rob(ex2) };
    std::cout << "Should be 12: " << ans_2 << std::endl;

    std::vector<int> ex3{ 4, 1, 2, 7, 5, 3, 1 };
    int ans_3{ rob(ex3) };
    std::cout << "Should be 14: " << ans_3 << std::endl;
}