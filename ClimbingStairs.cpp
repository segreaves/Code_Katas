#include <iostream>

int climbStairs(int n)
{
    if (n <= 1) return n;
    unsigned int first{ 1 };// Ways to get to step 0
    unsigned int second{ 1 };// Ways to get to step 1
    for (unsigned int i = 2; i <= n; ++i)
    {
        unsigned int curr_step{ first + second };
        first = second;
        second = curr_step;
    }
    return second;
}

int main()
{
    int ex1{ 2 };
    int ans_1{ climbStairs(ex1) };
    std::cout << "Should be 2: " << ans_1 << "\n";

    int ex2{ 3 };
    int ans_2{ climbStairs(ex2) };
    std::cout << "Should be 3: " << ans_2 << "\n";
}