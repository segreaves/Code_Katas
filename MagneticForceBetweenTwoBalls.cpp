#include <iostream>
#include <vector>
#include <algorithm>

bool checkDistance(std::vector<int>& position, const int m, int d)
{
    int counter = 1;
    int curr_pos = position[0];
    for (int i = 1; i < position.size() && counter < m; ++i)
    {
        if (position[i] >= curr_pos + d)
        {
            ++counter;
            curr_pos = position[i];
        }
    }
    return counter == m;
}

int maxDistance(std::vector<int>& position, int m)
{
    std::sort(position.begin(), position.end());
    int n = position.size();
    int start = 1;
    int end = position[n - 1] - position[0];
    int ans = 0;
    while (start <= end)
    {
        const int mid = (start + end) / 2;
        if (checkDistance(position, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> ex1{ 1, 2, 3, 4, 7 };
    std::cout << "Should be 3: " << maxDistance(ex1, 3) << "\n";
    
    std::vector<int> ex2{ 5, 4, 3, 2, 1, 1000000000 };
    std::cout << "Should be 999999999: " << maxDistance(ex2, 2) << "\n";

    std::vector<int> ex3{ 79, 74, 57, 22 };
    std::cout << "Should be 5: " << maxDistance(ex3, 4) << "\n";
}