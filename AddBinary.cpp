#include <iostream>

std::string addBinary(std::string a, std::string b)
{
    int i{ static_cast<int>(a.size()) - 1 };
    int j{ static_cast<int>(b.size()) - 1};
    int curr{ 0 };
    std::string result{""};
    while (i >= 0 || j >= 0 || curr == 1)
    {
        if (i >= 0) curr += a[i--] == '1';
        if (j >= 0) curr += b[j--] == '1';
        result = (curr % 2 ? "1" : "0") + result;
        curr /= 2;
    }
    return result;
}

int main()
{
    std::string a{"11"};
    std::string b{"1"};
    std::cout << "Should be 100: " << addBinary(a, b) << std::endl;
    a = "1010";
    b = "1011";
    std::cout << "Should be 10101: " << addBinary(a, b) << std::endl;
}