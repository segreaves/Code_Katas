#include <iostream>
#include <vector>
#include <limits>

class MinStack {
private:
    std::vector<std::pair<int, int>> m_arr;

public:
    MinStack()
    {
    }
    
    void push(int val)
    {
        if (m_arr.size() == 0) m_arr.push_back(std::pair<int, int>{val, val});
        else m_arr.push_back(std::pair<int, int>{val, std::min(m_arr[m_arr.size() - 1].second, val)});
    }
    
    void pop()
    {
        m_arr.pop_back();
    }
    
    int top()
    {
        int out{ m_arr.back().first };
        return out;
    }
    
    int getMin()
    {
        return m_arr.back().second;
    }
};

int main()
{
}
