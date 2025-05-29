#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> arr;
    for (int i = 1; i <= n; i++)
    {
        std::string curr{ "" };
        if (i % 3 == 0) curr += "Fizz";
        if (i % 5 == 0) curr += "Buzz";
        arr.emplace_back(curr.empty() ? std::to_string(i) : curr );
    }
    return arr;
}

std::string paste(const std::vector<std::string>& arr)
{
    std::string out{ "" };
    for (const auto& s : arr) out += s;
    return out;
}

int main()
{
    int ex_1{ 3 };
    std::string ans_1{ paste(fizzBuzz(ex_1)) };
    std::cout << "Should be [1, 2, Fizz]: " << ans_1 << std::endl;

    int ex_2{ 5 };
    std::string ans_2{ paste(fizzBuzz(ex_2)) };
    std::cout << "Should be [1, 2, Fizz, 4, Buzz]: " << ans_2 << std::endl;

    int ex_3{ 15 };
    std::string ans_3{ paste(fizzBuzz(ex_3)) };
    std::cout << "Should be [1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz]: " << ans_3 << std::endl;
}