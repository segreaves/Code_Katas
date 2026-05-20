#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums)
{
    size_t n{ nums.size() };
    if (n == 0) return false;
    int max_index{ nums[0] };

    int i{ 0 };
    while (i < n && i <= max_index)
    {
        if (i + nums[i] > max_index)
            max_index = i + nums[i];
        ++i;
    }
    return max_index >= n - 1;
}

int main()
{
    std::vector<int> ex1{2, 3, 1, 1, 4};
    std::vector<int> ex2{1, 2, 3};

    std::cout << canJump(ex2) << "\n";
}
