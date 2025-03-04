#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement(std::vector<int>& nums)
{
    std::unordered_map<int, int> m;
    for (const auto& i : nums)
    {
        m[i]++;
        if (m[i] > nums.size() / 2) return i;
    }
    return -1;
}

int main()
{
    std::vector<int> ex1{ 3, 2, 3 };
    std::cout << "Should be 3: " << majorityElement(ex1) << std::endl;

    std::vector<int> ex2{ 2, 2, 1, 1, 1, 2, 2 };
    std::cout << "Should be 2: " << majorityElement(ex2) << std::endl;
}