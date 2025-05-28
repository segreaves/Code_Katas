#include <iostream>
#include <vector>
#include <unordered_map>

class Recursive
{
    std::unordered_map<int, int> m;

public:
    int climbStairs(int n)
    {   
        if (m.find(n) != m.end()) return m[n];
        if (n <= 0) return 0;
        else if (n <= 2) return n;
        int n_1{ climbStairs(n - 1) };
        int n_2{ climbStairs(n - 2) };
        m[n] = n_1 + n_2;
        return m[n];
    }
};

int climbStairs(int n)
{
    if (n <= 1) return n;
    int first{ 1 };// Ways to get to step 0
    int second{ 1 };// Ways to get to step 1
    for (int i = 2; i <= n; i++)
    {
        int curr{ first + second };// Ways to get to step n
        first = second;
        second = curr;
    }
    return second;
}

int main()
{
    int ex1{ 2 };
    int ans_1{ climbStairs(ex1) };
    std::cout << "Should be 2: " << ans_1 << std::endl;

    int ex2{ 3 };
    int ans_2{ climbStairs(ex2) };
    std::cout << "Should be 3: " << ans_2 << std::endl;
}