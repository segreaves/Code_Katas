#include <iostream>

int getSum(int a, int b)
{
    unsigned int carry{ 0 };
    while (b != 0)
    {
        carry = (static_cast<unsigned int>(a) & static_cast<unsigned int>(b)) << 1;
        a = static_cast<unsigned int>(a) ^ static_cast<unsigned int>(b);
        b = carry;
    }
    return static_cast<int>(a);
}

int main()
{
}