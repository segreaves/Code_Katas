#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    std::vector<int> memo(n, 1);

    int answer{ 1 };
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                memo[i] = std::max(memo[i], memo[j] + 1);
            }
        }
        answer = std::max(answer, memo[i]);
    }

    return answer;
}

int main()
{
    std::vector<int> ex_1{ 10, 9, 2, 5, 3, 7, 101, 18 };
    std::cout << "Should be: 4: " << lengthOfLIS(ex_1) << "\n";

    std::vector<int> ex_2{ 0, 1, 0, 3, 2, 3 };
    std::cout << "Should be: 4: " << lengthOfLIS(ex_2) << "\n";
    
    std::vector<int> ex_3{ 7, 7, 7, 7, 7, 7, 7 };
    std::cout << "Should be: 1: " << lengthOfLIS(ex_3) << "\n";
}