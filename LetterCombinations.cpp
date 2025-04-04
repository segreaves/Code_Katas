#include <iostream>
#include <vector>
#include <unordered_map>

void iterateDigits(const std::string& digits, const std::unordered_map<char, std::string>& m,
    std::string curr, std::vector<std::string>& ans, int index)
{
    if (curr.length() == digits.length())
    {
        ans.push_back(curr);
        return;
    }

    char currentDigit{ digits[index] };
    std::string currentString{ m.at(currentDigit) };

    for (const auto& c : currentString)
    iterateDigits(digits, m, curr + c, ans, index + 1);
}

std::vector<std::string> letterCombinations(std::string digits)
{
    if (digits.length() == 0) return {};

    std::unordered_map<char, std::string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    std::vector<std::string> ans;
    iterateDigits(digits, m, "", ans, 0);
    return ans;
}

void printStringArray(std::vector<std::string> arr)
{
    std::cout << "[";
    for (const auto& s : arr) std::cout << "[" << s << "] ";
    std::cout << "]" << std::endl;
}

int main()
{
    std::string ex1{ "23" };
    printStringArray(letterCombinations(ex1));

    std::string ex2{ "" };
    printStringArray(letterCombinations(ex2));

    std::string ex3{ "2" };
    printStringArray(letterCombinations(ex3));
}