#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    const auto n{ nums.size() };
    if (n == 0) { return {}; }
    std::vector<int> result(n);
    // Store left products
    result[0] = 1;
    for (size_t i = 1; i < n; ++i)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }
    // Store right products and multiply by left products
    int right_prod{ 1 };
    for (int i = static_cast<int>(n) - 1; i >= 0; --i)
    {
        result[i] *= right_prod;
        right_prod *= nums[i];
    }
    return result;
}

void print(const std::vector<int>& arr)
{
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> ex1{ 1, 2, 3, 4 };
    const auto ans1{ productExceptSelf(ex1) };
    print(ans1);

    std::vector<int> ex2{ -1, 1, 0, -3, 3 };
    const auto ans2{ productExceptSelf(ex2) };
    print(ans2);
}