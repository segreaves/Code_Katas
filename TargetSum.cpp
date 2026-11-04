#include <iostream>
#include <vector>

static constexpr int OFFSET{ 1000 };

int dfs(unsigned int i, int current_sum, const std::vector<int>& nums, int target, std::vector<std::vector<int>>& memo)
{
    // Base case
    if (i == nums.size())
    {
        return current_sum == target ? 1 : 0;
    }

    // Memoization lookup
    if (memo[i][current_sum + OFFSET] != -1) return memo[i][current_sum + OFFSET];

    memo[i][current_sum + OFFSET] = dfs(i + 1, current_sum + nums[i], nums, target, memo) + dfs(i + 1, current_sum - nums[i], nums, target, memo);

    return memo[i][current_sum + OFFSET];
}

int findTargetSumWays(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>> memo(
        nums.size(),
        std::vector<int>(2001, -1)
    );

    return dfs(0, 0, nums, target, memo);
}

int main()
{
    std::vector<int> ex_1{ 1, 1, 1, 1, 1 };
    std::cout << "Should be 5: " << findTargetSumWays(ex_1, 3) << "\n";
}