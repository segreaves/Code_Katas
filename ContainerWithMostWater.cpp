#include <vector>
#include <iostream>

/*
The amount of water a container can store is the area
of the square formed by the distance between the to indexes and the height
of the lower of the two.
*/
template<typename T>
T maxWater(std::vector<T> heights)
    {
        // If empty vector then return 0
        if (heights.size() == 0) { return static_cast<T>(0); }
        T max_water{ 0 };
        // Rolling window
        int l{ 0 }, last_l = l;
        int r{ static_cast<int>(heights.size() - 1) }, last_r = r;
        while (l < r)
        {
            // Calculate the water amount
            T water{ (r - l) * std::min(heights[l], heights[r]) };
            // Update max_water if needed
            if (max_water < water) max_water = water;

            if (heights[l] < heights[r]) ++l;
            else --r;
        }
        return max_water;
    }

int main()
{
    std::cout << maxWater<int>({ 5, 9, 2, 1, 4 }) << std::endl;
}