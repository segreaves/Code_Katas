#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums)
{
    int n = nums.size();
    if (nums[0] < nums[n - 1]) return nums[0];
    int start = 0;
    int end = n - 1;
    int min = nums[n - 1];
    while (start <= end)
    {
        const int m = (start + end) / 2;
        if (nums[m] <= min) // Update min
        {
            min = nums[m];
            end = m - 1;
        }
        else // Minimum must be to the right
        {
            start = m + 1;
        }
    }
    return min;
}

int main()
{
    std::vector<int> ex1{ 3, 4, 5, 1, 2 };
    std::cout << "Should be 1: " << findMin(ex1) << "\n";

    std::vector<int> ex2{ 4, 5, 6, 7, 0, 1, 2 };
    std::cout << "Should be 0: " << findMin(ex2) << "\n";
    std::vector<int> ex3{ 11, 13, 15, 17 };
    std::cout << "Should be 11: " << findMin(ex3) << "\n";
}
