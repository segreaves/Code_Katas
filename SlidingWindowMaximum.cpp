#include <iostream>
#include <vector>
#include <deque>

// nums.length is guaranteed to be non-zero
// k is guaranteed to be [1, nums.size() ]
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
    int n{ static_cast<int>(nums.size()) };
    std::vector<int> output;
    output.reserve(n - k + 1);
    std::deque<int> q;
    for (int r = 0; r < n; ++r)
    {
        // Remove numbers from q that are smaller than nums[r]
        while (q.size() > 0 && nums[q.back()] < nums[r])
            q.pop_back();
        q.emplace_back(r);
        // Pop indices outside the window
        if (q.front() <= r - k)
            q.pop_front();
        // Update output only if window is large enough
        if (r >= k - 1)
            output.emplace_back(nums[q.front()]);
    }
    return output;
}

void print(const std::vector<int>& arr)
{
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> arr1{ 1, 3, -1, -3, 5, 3, 6, 7 };
    auto ans1{ maxSlidingWindow(arr1, 3) };
    std::cout << "Should be 3, 3, 5, 5, 6, 7: " << "\n";
    print(ans1);

    std::vector<int> arr2{ 7, 2, 4 };
    auto ans2{ maxSlidingWindow(arr2, 2) };
    std::cout << "Should be 7, 4: " << "\n";
    print(ans2);
}
