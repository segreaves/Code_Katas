#include <vector>
#include <iostream>

int maxWater(std::vector<int>& height)
{
    // Initialize two pointers
    int l{ 0 };
    int r{ static_cast<int>(height.size()) - 1 };
    // Initialize result
    int max_water{ 0 };
    while (l < r)
    {
        // Calculate the height that can hold water
        int l_height{ height[l] };
        int r_height{ height[r] };
        int min_height{ std::min(l_height, r_height) };
        // Calculate current water amount
        int water{ (r - l) * min_height };
        // Update the max
        max_water = std::max(max_water, water);
        // Iterate pointer
        if (l_height < r_height) ++l;
        else --r;
    }
    return max_water;
}

int main()
{
    std::vector<int> ex1{ { 1, 8, 6, 2, 5, 4, 8, 3, 7 } };
    std::cout << "Should be 49: " << maxWater(ex1) << "\n";

    std::vector<int> ex2{ {1, 1} };
    std::cout << "Should be 1: " << maxWater(ex2) << "\n";
}
