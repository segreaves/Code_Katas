#include <iostream>
#include <vector>
#include <limits>

int maxProfit(std::vector<int>& prices)
{
    int buyPrice{ std::numeric_limits<int>::max() };
    int profit{ 0 };
    for (const auto& price : prices)
    {
        if (price < buyPrice) buyPrice = price;
        else profit = std::max(profit, price - buyPrice);
    }
    return profit;
}

int main()
{
    std::vector<int> ex1{ 7, 1, 5, 3, 6, 4 };
    int ans_1{ maxProfit(ex1) };
    std::cout << "Should be 5: " << ans_1 << std::endl;

    std::vector<int> ex2 { 7, 6, 4, 3, 1 };
    int ans_2{ maxProfit(ex2) };
    std::cout << "Should be 0: " << ans_2 << std::endl;

    std::vector<int> ex3{ 7, 3, 25, 1, 5, 4 };
    int ans_3{ maxProfit(ex3) };
    std::cout << "Should be 22: " << ans_3 << std::endl;
}