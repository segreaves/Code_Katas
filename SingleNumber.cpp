#include <iostream>
#include <vector>

int SingleNumber(std::vector<int>& nums)
{
    int ans{ 0 };
    for (const auto& e : nums) ans ^= e;
    return ans;
}

int main()
{
    std::vector<int> ex1{ 2, 2, 1 };
    std::cout << "Should be 1: " << SingleNumber(ex1) << '\n';
    std::vector<int> ex2{ 4, 1, 2, 1, 2 };
    std::cout << "Should be 4: " << SingleNumber(ex2) << '\n';
    std::vector<int> ex3{ 1 };
    std::cout << "Should be 1: " << SingleNumber(ex3) << '\n';
    std::vector<int> ex4{ -1, -1, -3 };
    std::cout << "Should be -3: " << SingleNumber(ex4) << '\n';
}
