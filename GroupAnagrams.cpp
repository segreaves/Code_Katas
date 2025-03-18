#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, int> m;
    std::vector<std::vector<std::string>> output;
    for (const auto& s : strs)
    {
        std::string sorted_s{ s };
        std::sort(sorted_s.begin(), sorted_s.end());
        if (m.find(sorted_s) == m.end())
        {
            output.push_back(std::vector<std::string>{});
            m[sorted_s] = output.size() - 1;
        }
        output[m[sorted_s]].push_back(s);
    }
    return output;
}

void printAnagrams(std::vector<std::vector<std::string>>& strs)
{
    for (const auto& vec : strs)
    {
        for (const auto& s : vec)
        {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "-----" << std::endl;
    std::vector<std::string> ex1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> output1{ groupAnagrams(ex1) };
    printAnagrams(output1);

    std::cout << "-----" << std::endl;
    std::vector<std::string> ex2 = {""};
    std::vector<std::vector<std::string>> output2{ groupAnagrams(ex2) };
    printAnagrams(output2);

    std::cout << "-----" << std::endl;
    std::vector<std::string> ex3 = {"a"};
    std::vector<std::vector<std::string>> output3{ groupAnagrams(ex3) };
    printAnagrams(output3);
}