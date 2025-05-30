#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

int recursive(const std::vector<int>& coins, const int& amount, std::unordered_map<int, int>& m)
{
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (m.find(amount) != m.end()) return m[amount];
    int minimum{ std::numeric_limits<int>::max() };
    bool solution{ false };
    for (const auto& c : coins)
    {
        int res{ recursive(coins, amount - c, m) };
        if (res >= 0 && res < minimum)
        {
            solution = true;
            minimum = res + 1;
        }
    }
    m.emplace(std::pair<int, int>(amount, solution ? minimum : -1));
    return m[amount];
}

/*
int coinChange(std::vector<int>& coins, int amount)
{
    if (amount <= 0) return 0;
    std::unordered_map<int, int> m;
    return recursive(coins, amount, m);
}
*/

/// @brief Dynamic programming approach. Could improve speed if coins vector was guaranteed to be sorted in increasing value.
/// @param coins 
/// @param amount 
/// @return 
int coinChange(std::vector<int>& coins, int amount)
{
    if (amount <= 0) return 0;
    int MAX_INT{ std::numeric_limits<int>::max() };
    std::vector<int> arr(amount + 1, MAX_INT);
    arr[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (const auto& coin : coins)
            if (coin <= i && i - coin >= 0 && arr[i - coin] != MAX_INT)
                    arr[i] = std::min(arr[i], arr[i - coin] + 1);
    return arr[amount] == MAX_INT ? -1 : arr[amount];
}

int main()
{
    std::vector<int> coins_1{ 1, 2, 5 };
    int amt_1{ 11 };
    int ans_1{ coinChange(coins_1, amt_1) };
    std::cout << "Should be 3:" << ans_1 << std::endl;

    std::vector<int> coins_2{ 2 };
    int amt_2{ 3 };
    int ans_2{ coinChange(coins_2, amt_2) };
    std::cout << "Should be -1:" << ans_2 << std::endl;

    std::vector<int> coins_3{ 1 };
    int amt_3{ 0 };
    int ans_3{ coinChange(coins_3, amt_3) };
    std::cout << "Should be 0:" << ans_3 << std::endl;
}