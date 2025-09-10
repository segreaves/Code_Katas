#include <iostream>
#include <vector>

void print(const std::vector<int>& arr)
{
    for (const auto& item : arr)
        std::cout << item << " ";
    std::cout << "\n";
}

void sortColors(std::vector<int>& nums)
{
    int n{ static_cast<int>(nums.size()) };
    int l{ 0 };
    int r{ n - 1 };
    int i{ 0 };
    while (i <= r)
    {
        if (nums[i] == 0)
            std::swap(nums[i++], nums[l++]);
        else if (nums[i] == 2)
            std::swap(nums[i], nums[r--]);
        else ++i;
    }
}

int main()
{
    std::vector<int> arr1{ 2, 0, 2, 1, 1, 0 };
    std::cout << "Original: ";
    print(arr1);
    sortColors(arr1);
    std::cout << "Should be 0 0 1 1 2 2:\n";
    print(arr1);

    std::vector<int> arr2{ 2, 0, 1 };
    std::cout << "Original: ";
    print(arr2);
    sortColors(arr2);
    std::cout << "Should be 0 1 2:\n";
    print(arr2);

    std::vector<int> arr3{ 1, 2 };
    std::cout << "Original: ";
    print(arr3);
    sortColors(arr3);
    std::cout << "Should be 1 2:\n";
    print(arr3);
}