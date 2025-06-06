#include <iostream>
#include <vector>

int trap(std::vector<int>& height)
{
    int n{ static_cast<int>(height.size()) };
    if (n <= 2) return 0;
    std::vector<int> max_l(n, 0);
    max_l[0] = height[0];
    std::vector<int> max_r(n, 0);
    max_r[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        max_l[i] = std::max(max_l[i - 1], height[i]);
        max_r[n - i - 1] = std::max(max_r[n - i], height[n - i - 1]);
    }
    int w{ 0 };
    for (int i = 1; i < n - 1; i++)
    {
        int lowest_max_height{ std::min(max_l[i - 1], max_r[i + 1]) };
        int curr_height{ height[i] };
        w += (lowest_max_height > curr_height ? lowest_max_height - curr_height : 0);
    }
    return w;
}

int main()
{
    std::vector<int> ex_1{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    std::cout << "Should be 6: " << trap(ex_1) << std::endl;

    std::vector<int> ex_2{ 4, 2, 0, 3, 2, 5 };
    std::cout << "Should be 9: " << trap(ex_2) << std::endl;
}