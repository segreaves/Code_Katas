#include <iostream>
#include <vector>

enum Direction
{
    right = 0,
    left,
    up,
    down
};

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
    size_t m{ matrix.size() };
    size_t n{ matrix[0].size() };
    int top{ 0 };
    int bottom{ static_cast<int>(m) - 1 };
    int left{ 0 };
    int right{ static_cast<int>(n) - 1 };

    Direction dir{ Direction::right };
    int r{ 0 };
    int c{ 0 };

    std::vector<int> spiral{ std::vector<int>{} };
    spiral.reserve(m * n);
    while (top <= bottom && left <= right)
    {
        spiral.emplace_back(matrix[r][c]);
        switch (dir)
        {
            case Direction::right:
            if (c == right)
            {
                dir = Direction::down;
                ++top;
                ++r;
            }
            else ++c;
            break;
            case Direction::down:
            if (r == bottom)
            {
                dir = Direction::left;
                --right;
                --c;
            }
            else ++r;
            break;
            case Direction::left:
            if (c == left)
            {
                dir = Direction::up;
                --bottom;
                --r;
            }
            else --c;
            break;
            case Direction::up:
            if (r == top)
            {
                dir = Direction::right;
                ++left;
                ++c;
            }
            else --r;
            break;
        }
    }
    return spiral;
}

void printArray(std::vector<int> arr)
{
    for (const auto& e : arr)
        std::cout << e << ", ";
    std::cout << "\n";
}

int main()
{
    std::vector<std::vector<int>> m1{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::cout << "Should be [1,2,3,6,9,8,7,4,5]:\n";
    printArray(spiralOrder(m1));

    std::vector<std::vector<int>> m2{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    std::cout << "Should be [1,2,3,4,8,12,11,10,9,5,6,7]:\n";
    printArray(spiralOrder(m2));
}