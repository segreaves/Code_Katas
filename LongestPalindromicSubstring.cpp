#include <iostream>
#include <string>
#include <vector>

std::string longestPalindrome(std::string s)
{
    int n{ static_cast<int>(s.length()) };
    if (n <= 1) return s;

    std::string longest_palindrome{ s[0] };
    std::vector<std::vector<bool>> m(n, std::vector<bool>(n, false));
    for (int r = 0; r < n; r++)
    {
        m[r][r] = true;
        for (int l = 0; l < r; l++)
        {
            if (s[l] == s[r] && (r - l <= 2 || m[l + 1][r - 1]))
            {
                m[l][r] = true;
                if (r - l + 1 > longest_palindrome.length()) longest_palindrome = s.substr(l, r - l + 1);
            }
            else m[l][r] = false;
        }
    }
    return longest_palindrome;
}

int main()
{
    std::string ex_1{ "babad" };
    std::cout << "Should be bab: " << longestPalindrome(ex_1) << std::endl;

    std::string ex_2{ "cbbd" };
    std::cout << "Should be bb: " << longestPalindrome(ex_2) << std::endl;

    std::string ex_3{ "ac" };
    std::cout << "Should be a: " << longestPalindrome(ex_3) << std::endl;
}