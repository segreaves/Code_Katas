#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& arr)
{
    size_t l{ 0 };
    for (const auto& num : arr)
        if (num != 0) arr[l++] = num;
    for (size_t i = l; i < arr.size(); ++i)
        arr[i] = 0;
}

void print(std::vector<int>& arr)
{
    for (const auto& elem : arr)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    std::cout << "Should be 1 3 12 0 0: " << std::endl;
    std::vector<int> ex1{0, 1, 0, 3, 12};
    moveZeroes(ex1);
    print(ex1);
    std::cout << "Should be 0: " << std::endl;
    std::vector<int> ex2{0};
    moveZeroes(ex2);
    print(ex2);
}

