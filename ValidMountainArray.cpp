#include <vector>
#include <iostream>

template<typename T>
bool ValidMountainArray(std::vector<T> arr)
{
    int n { static_cast<int>(arr.size()) };
    int l{ 0 };
    int r{ n - 1 };
    while (l + 1 < n && arr[l] < arr[l + 1]) ++l;
    while (r - 1 > 0 && arr[r - 1] > arr[r]) r--;
    return l > 0 && r < n - 1 && l == r;
}

int main()
{
    std::cout << "Should be false: " << ValidMountainArray(std::vector({0, 1})) << std::endl;
    std::cout << "Should be true: " << ValidMountainArray(std::vector({0, 1, 2, 3, 2, 1})) << std::endl;
    std::cout << "Should be false: " << ValidMountainArray(std::vector({0, 1, 2, 3, 2, 3})) << std::endl;
    std::cout << "Should be false: " << ValidMountainArray(std::vector({3, 2, 1, 2, 3})) << std::endl;
    std::cout << "Should be true: " << ValidMountainArray(std::vector({0, 3, 2, 1})) << std::endl;
}
