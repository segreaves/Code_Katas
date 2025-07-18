#include <iostream>
#include <vector>

int trap(const std::vector<int>& height)
{
    const auto n{ height.size() };
    std::vector<int> max_l(n);
    std::vector<int> max_r(n);
    auto l{ 0 };
    auto r{ 0 };
    for (size_t i = 0; i < n; ++i)
    {
        l = std::max(l, height[i]);
        r = std::max(r, height[n - 1 - i]);
        max_l[i] = l;
        max_r[n - 1 - i] = r;
    }
    auto water{ 0 };
    for (size_t i = 1; i < n - 1; ++i)
    {
        const auto height_l{ max_l[i] };
        const auto height_r{ max_r[i] };
        const auto min_height{ std::min(height_l, height_r) };
        water += std::max(0, min_height - height[i]);
    }
    return water;
}

int main()
{
    const std::vector<int> ex_1{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    std::cout << "Should be 6: " << trap(ex_1) << std::endl;

    const std::vector<int> ex_2{ 4, 2, 0, 3, 2, 5 };
    std::cout << "Should be 9: " << trap(ex_2) << std::endl;
}
