#include <iostream>
#include <vector>


int coinChange(std::vector<int>& coins, int amount)
{
    if (amount <= 0) return 0;
    std::vector<int> arr(amount + 1, INT_MAX);
    arr[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        // Get the minimum number of coins that can make up i
        for (const auto& coin_val : coins)
        {
            // Decide if this amount can bemade up of the coins available
            if ((i  - coin_val >= 0) && (arr[i - coin_val] != INT_MAX))
            {
                arr[i] = std::min(arr[i], arr[i - coin_val] + 1);
            }
        }
    }
    return arr[amount] == INT_MAX ? -1 : arr[amount];
    
}

int main()
{
    std::vector<int> coins_1{ 1, 2, 5 };
    int amt_1{ 11 };
    int ans_1{ coinChange(coins_1, amt_1) };
    std::cout << "Should be 3:" << ans_1 << "\n";

    std::vector<int> coins_2{ 2 };
    int amt_2{ 3 };
    int ans_2{ coinChange(coins_2, amt_2) };
    std::cout << "Should be -1:" << ans_2 << "\n";

    std::vector<int> coins_3{ 1 };
    int amt_3{ 0 };
    int ans_3{ coinChange(coins_3, amt_3) };
    std::cout << "Should be 0:" << ans_3 << "\n";
}
