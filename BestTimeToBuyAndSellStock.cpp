#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices)
{
    auto n{ prices.size() };
    if (n == 0) return 0;
    auto buy_price{ prices[0] };
    auto profit{ 0 };
    for (size_t i = 1; i < n; ++i)
    {
        if (prices[i] < buy_price) buy_price = prices[i];
        else profit = std::max(profit, prices[i] - buy_price);
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
