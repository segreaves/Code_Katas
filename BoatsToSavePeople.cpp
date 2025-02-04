#include <iostream>
#include <vector>
#include <algorithm>

int minimum_boats(std::vector<int> people, int limit)
{
    int len{ static_cast<int>(people.size()) };
    if (len == 0) { return 0; }

    std::sort(people.begin(), people.end());
    int l{ 0 };
    int r{ len - 1 };
    // Start with 0 boats
    int boats{ 0 };
    // Try to match heaviest and lightest people together
    while (l < r)
    {
        boats++;
        // If both people fit on the boat then also increment the lighter person
        if (people[l] + people[r--] <= limit) l++;
    }
    return l == r ? boats + 1 : boats;
}

int main()
{
    std::cout << "Should be 1: " << minimum_boats({1, 2}, 3) << std::endl;
    std::cout << "Should be 3: " << minimum_boats({3, 2, 2, 1}, 3) << std::endl;
    std::cout << "Should be 4: " << minimum_boats({3, 5, 3, 4}, 5) << std::endl;
}
