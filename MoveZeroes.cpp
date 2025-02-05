#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& arr)
{
    int l{ 0 };
    int r{ static_cast<int>(arr.size()) };
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]) arr[l++] = arr[i];
        else r--;
    }
    for (int j = r; j < arr.size(); j++)
        arr[j] = 0;
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
