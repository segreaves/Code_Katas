#include <iostream>

int hammingWeight(int n)
{
    int count{ 0 };
    while (n != 0)
    {
        n &= (n - 1);
        ++count;
    }
    return count;
}

int main()
{
    std::cout << "Should be 3: " << hammingWeight(11) << "\n";
    std::cout << "Should be 1: " << hammingWeight(128) << "\n";
    std::cout << "Should be 30: " << hammingWeight(2147483645) << "\n";
}