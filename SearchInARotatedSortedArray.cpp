#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;
    while (start <= end)
    {
        const int m = (start + end) / 2;
        if (nums[m] >= nums[0] && target < nums[0])
            start = m + 1;
        else if (nums[m] < nums[0] && target >= nums[0])
            end = m - 1;
        else
        {
            if (target == nums[m]) return m;
            else if (target < nums[m])
                end = m - 1;
            else if (target > nums[m])
                start = m + 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> ex1{ 4, 5, 6, 7, 0, 1, 2 };
    std::cout << "Should be 4: " << search(ex1, 0) << "\n";
    std::cout << "Should be -1: " << search(ex1, 3) << "\n";
    std::vector<int> ex2{ 5, 1, 3 };
    std::cout << "Should be 0: " << search(ex2, 5) << "\n";
}
