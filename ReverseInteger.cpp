#include <iostream>

int reverse(int x)
{
    if (x == INT_MIN) return 0;

    bool is_pos{ x >= 0 };
    x = abs(x);

    int reversed = 0;

    while (x != 0)
    {
        int digit{ x % 10 };
        x /= 10;

        if (reversed > INT_MAX / 10) return 0;
        reversed = reversed * 10 + digit;
    }

    return is_pos ? reversed : -reversed;
}

int main()
{
    std::cout << reverse(123) << "\n";
    std::cout << reverse(-123) << "\n";
    std::cout << reverse(120) << "\n";
    std::cout << reverse(1534236469) << "\n"; // overflow -> 0
}