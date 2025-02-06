#include <iostream>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s)
{
    if (!s.size()) { return 0; }
    std::unordered_map<char, int> m;
    int l{0};
    int ans{0};
    for (int r = 0; r < s.size(); r++)
    {
        if (m.find(s[r]) != m.end() && m[s[r]] >= l) l = m[s[r]] + 1;
        m[s[r]] = r;
        ans = std::max(ans, r - l + 1);
    }
    return ans;
}

int main()
{
    int ans1{lengthOfLongestSubstring("abcabcbb")};
    std::cout << "Should be 3:" << ans1 << std::endl;
    int ans2{lengthOfLongestSubstring("bbbbb")};
    std::cout << "Should be 1:" << ans2 << std::endl;
    int ans3{lengthOfLongestSubstring("pwwkew")};
    std::cout << "Should be 3:" << ans3 << std::endl;
    int ans4{lengthOfLongestSubstring("abcdecabfgh")};
    std::cout << "Should be 8:" << ans4 << std::endl;
}