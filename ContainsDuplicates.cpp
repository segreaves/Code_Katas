#include <iostream>
#include <vector>
#include <unordered_map>

bool containsDuplicates(std::vector<int>& nums)
{
    std::unordered_map<int, bool> m;
    for (const auto& e : nums)
    {
        if (m[e]) return true;
        else m[e] = true;
    }
    return false;
}

int main()
{
    std::vector<int> ex1{1, 2, 3, 1};
    std::cout << "Should be true: " << containsDuplicates(ex1) << std::endl;

    std::vector<int> ex2{1, 2, 3, 4};
    std::cout << "Should be false: " << containsDuplicates(ex2) << std::endl;
    
    std::vector<int> ex3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << "Should be true: " << containsDuplicates(ex3) << std::endl;
}