#include <iostream>
#include <vector>

int maxProduct(std::vector<int>& nums)
{
    int n{ static_cast<int>(nums.size()) };
    if (n == 1) return nums[0];
    int result{ 0 };
    int lr_prod{ 1 };
    int rl_prod{ 1 };
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] != 0)
        {
            lr_prod = lr_prod * nums[i];
            if (result < lr_prod) result = lr_prod;
        } else lr_prod = 1;
        if (nums[n - i - 1] != 0)
        {
            rl_prod = rl_prod * nums[n - i - 1];
            if (result < rl_prod) result = rl_prod;
        } else rl_prod = 1;
    }
    return result;
}

int main()
{
    std::vector<int> arr1{ 2, 3, -2, 4 };
    std::cout << "Should be 6: " << maxProduct(arr1) << "\n";

    std::vector<int> arr2{ -2, 0, -1 };
    std::cout << "Should be 0: " << maxProduct(arr2) << "\n";
}