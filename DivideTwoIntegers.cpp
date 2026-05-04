#include <iostream>

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
     bool pos{(dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) };

    long a{ abs(static_cast<long>(dividend)) };
    long b{ abs(static_cast<long>(divisor)) };

    int quotient{ 0 };

    while (a >= b)
    {
        int i{ 0 };
        while ((b << i) <= a) ++i;
        quotient += (1 << (i - 1));
        a -= (b << (i - 1));
    }

    return pos ? quotient : -quotient;
}

int main()
{
}
