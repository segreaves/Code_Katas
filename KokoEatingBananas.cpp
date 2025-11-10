#include <iostream>
#include <vector>
#include <algorithm>

long int eatBananas(std::vector<int>& piles, int k)
{
    long int hours{ 0 };
    for (const auto elem : piles)
        hours += elem % k == 0 ? elem / k : (elem / k) + 1;
    return hours;
}

int minEatingSpeed(std::vector<int>& piles, int h)
{
    long int start = 1;
    long int end = *std::max_element(piles.begin(), piles.end());
    long int ans = end;
    while (start <= end)
    {
        const int m = (start + end) / 2;
        if (eatBananas(piles, m) > (long) h)
            start = m + 1;
        else
        {
            ans = m;
            end = m - 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> ex1{ 3, 6, 7, 11 };
    std::cout << "Should be 4: " << minEatingSpeed(ex1, 8) << "\n";

    std::vector<int> ex2{ 30, 11, 23, 4, 20 };
    std::cout << "Should be 30: " << minEatingSpeed(ex2, 5) << "\n";
    std::cout << "Should be 23: " << minEatingSpeed(ex2, 6) << "\n";

    std::vector<int> ex3{ 1000000000 };
    std::cout << "Should be 500000000: " << minEatingSpeed(ex3, 2) << "\n";
}