#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int>& arr)
{
    for (const auto& e : arr)
        std::cout << e << " ";
    std::cout << "\n";
}

void rotate(std::vector<int>& nums, int k)
{
    auto n{ nums.size() };
    k = k % n;
    if (k == 0) return;
    // Reverse the entire array
    std::reverse(nums.begin(), nums.end());
    // Reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);
    // Reverse the last k elements
    std::reverse(nums.begin() + k, nums.end());
}

int main()
{
    std::vector<int> arr1{ 1, 2, 3, 4, 5, 6, 7 };
    rotate(arr1, 3);
    std::cout << "Should be [5, 6, 7, 1, 2, 3, 4]\n";
    print(arr1);

    std::vector<int> arr2{ -1, -100, 3, 99 };
    rotate(arr2, 2);
    std::cout << "Should be [3, 99, -1, -100]\n";
    print(arr2);
}