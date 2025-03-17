#include <iostream>
#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t)
{
    int len_s{ static_cast<int>(s.size()) };
    int len_t{ static_cast<int>(t.size()) };
    if (len_s < len_t) return "";
    std::unordered_map<char, int> m_s, m_t;
    for (const auto& c : t) m_t[c]++;
    int l{ 0 };
    int count{ 0 };
    int min_len{ INT_MAX };
    int start_index{ -1 };
    for (int r = 0; r < len_s; ++r)
    {
        char c{ s[r] };
        m_s[c]++;
        if (m_t.find(c) != m_t.end() && m_s[c] <= m_t[c]) count++;
        if (count == len_t)
        {
            while (m_t.find(s[l]) == m_t.end() || m_s[s[l]] > m_t[s[l]])
            {
                if (m_s.find(s[l]) != m_s.end()) m_s[s[l]]--;
                l++;
            }
            int window_len{ r - l + 1 };
            if (min_len > window_len)
            {
                min_len = window_len;
                start_index = l;
            }
            if (min_len == t.size()) return s.substr(start_index, min_len);
        }
    }
    if (start_index == -1) return "";
    return s.substr(start_index, min_len);
}

int main()
{
    std::string s1{ "ADOBECODEBANC" };
    std::string t1{ "ABC" };
    std::string ans1{ minWindow(s1, t1) };
    std::cout << "Should be BANC: " << "'" << ans1 << "'" << std::endl;

    std::string s2{ "a" };
    std::string t2{ "a" };
    std::string ans2{ minWindow(s2, t2) };
    std::cout << "Should be a: " << "'" << ans2 << "'" << std::endl;

    std::string s3{ "a" };
    std::string t3{ "aa" };
    std::string ans3{ minWindow(s3, t3) };
    std::cout << "Should be '': " << "'" << ans3 << "'" << std::endl;
}