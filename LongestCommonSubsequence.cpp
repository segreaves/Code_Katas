#include <iostream>
#include <string>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2) {
    const int m{ static_cast<int>(text1.size()) };
    const int n{ static_cast<int>(text2.size()) };

    std::vector<int> prev(n + 1, 0);
    std::vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = std::max(
                    prev[j],
                    curr[j - 1]
                );
            }
        }
        prev = curr;
    }
    return curr[n];
}

int main()
{
    std::cout << longestCommonSubsequence("abcdef", "abc") << "\n";
    std::cout << longestCommonSubsequence("abc", "def") << "\n";
}
