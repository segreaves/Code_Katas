#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums)
{
    int n{ static_cast<int>(nums.size()) };
    int majority_element{ nums[0] };
    int count{ 1 };
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] == majority_element) ++count;
        else if (--count == 0)
        {
            majority_element = nums[i];
            count = 1;
        }
    }
    return majority_element;
}

int main()
{
    std::vector<int> arr1{ 3, 2, 3 };
    std::cout << "Should be 3: " << majorityElement(arr1) << "\n";

    std::vector<int> arr2{ 2, 2, 1, 1, 1, 2, 2 };
    std::cout << "Should be 2: " << majorityElement(arr2) << "\n";
}
