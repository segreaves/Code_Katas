#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target)
{
    int ans = nums.size();
    int start{ 0 };
    int end = ans - 1;
    int m = 0;
    while (start <= end)
    {
        m = (start + end) / 2;
        int num{ nums[m] };
        if (num < target)
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
    std::vector<int> ex1{ 1, 3, 5, 6 };
    std::cout << "Should be 2: ";
    std::cout << searchInsert(ex1, 5) << "\n";

    std::cout << "Should be 1: ";
    std::cout << searchInsert(ex1, 2) << "\n";

    std::cout << "Should be 4: ";
    std::cout << searchInsert(ex1, 7) << "\n";
}