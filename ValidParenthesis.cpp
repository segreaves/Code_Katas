#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s)
{
    if (s == "") return true;

    std::unordered_map<char, char> brackets
    {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };

    std::stack<char> stack;
    for (const auto& c : s)
    {
        // Check if c is an openning bracket
        if (brackets.find(c) != brackets.end()) stack.push(brackets[c]);// Open bracket
        else
        {
            if (stack.size() == 0 || stack.top() != c) return false;//Close inappropriate bracket
            stack.pop();// Close appropriate bracket
        }
    }
    return stack.size() == 0;
}

int main()
{
    std::cout << "Should be 1: " << isValid("()") << std::endl;
    std::cout << "Should be 1: " << isValid("()[]{}") << std::endl;
    std::cout << "Should be 0: " << isValid("[") << std::endl;
    std::cout << "Should be 0: " << isValid("(]") << std::endl;
    std::cout << "Should be 1: " << isValid("([])") << std::endl;
}