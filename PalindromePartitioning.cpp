#include <iostream>
#include <vector>

bool isPalindrome(std::string s)
{
    if (s.size() == 0) return false;
    if (s.size() == 1) return true;
    int l{ 0 };
    int r{ static_cast<int>(s.size() - 1) };
    while (l < r)
    {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void solution(const std::string s, std::vector<std::string> curr, std::vector<std::vector<std::string>>& ans)
{
    if (s.size() == 0) ans.push_back(curr);
    for (int i = 1; i <= s.size(); i++)
    {
        std::string l{ s.substr(0, i) };
        if (isPalindrome(l))
        {
            curr.push_back(l);
            solution(s.substr(i), curr, ans);
            curr.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> partition;
    solution(s, partition, ans);
    return ans;
}

void printArray(std::vector<std::vector<std::string>> arr)
{
    std::cout << "[";
    for (const auto& subArr : arr)
    {
        std::cout << "[";
        for (const auto& e : subArr)
            std::cout << e << " ";
        std::cout << "]";
    }
    std::cout << "]";
}

int main()
{
    std::cout << "Ex 1:" << std::endl;
    std::string ex1{ "aab" };
    const auto ans1{ partition(ex1) };
    printArray(ans1);

    std::cout << std::endl;
    std::cout << "Ex 2:" << std::endl;
    std::string ex2{ "a" };
    const auto ans2{ partition(ex2) };
    printArray(ans2);
}