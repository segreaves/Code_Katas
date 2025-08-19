#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    const auto m{ matrix.size() };// Guaranteed > 0
    const auto n{ matrix[0].size() };// Guaranteed > 0
    bool first_row{ false };
    bool first_col{ false };
    // Mark rows and columns that need to become 0 by zeroing the 1st element
    for (size_t r = 0; r < m; ++r)
    {
        for (size_t c = 0; c < n; ++c)
        {
            if (matrix[r][c] == 0)
            {
                matrix[r][0] = 0;
                matrix[0][c] = 0;
                if (r == 0) first_row = true;
                if (c == 0) first_col = true;
            }
        }
    }
    // Traverse backwards and set elements to 0
    for (int r = static_cast<int>(m) - 1; r >= 0; --r)
        for (int c = static_cast<int>(n) - 1; c >= 0; --c)
            if (matrix[r][0] == 0 || matrix[0][c] == 0)
                if (r == 0) matrix[r][c] = first_row ? 0 : matrix[r][c];
                else if (c == 0) matrix[r][c] = first_col ? 0 : matrix[r][c];
                else matrix[r][c] = 0;
}

void printMat(const std::vector<std::vector<int>>& mat)
{
    for (size_t i = 0; i < mat.size(); ++i)
    {
        for (size_t j = 0; j < mat[0].size(); ++j)
            std::cout << mat[i][j] << " ";
        std::cout << "\n";
    }
}

int main()
{
    std::cout << "m1:\n";
    std::vector<std::vector<int>> m1{ {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
    printMat(m1);
    setZeroes(m1);
    std::cout << "m1 zeroed:\n";
    printMat(m1);

    std::cout << "m2:\n";
    std::vector<std::vector<int>> m2{ {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
    printMat(m2);
    setZeroes(m2);
    std::cout << "m2 zeroed:\n";
    printMat(m2);

    std::cout << "m3:\n";
    std::vector<std::vector<int>> m3{ {1}, {0} };
    printMat(m3);
    setZeroes(m3);
    std::cout << "m3 zeroed:\n";
    printMat(m3);

    std::cout << "m4:\n";
    std::vector<std::vector<int>> m4{ {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0} };
    printMat(m4);
    setZeroes(m4);
    std::cout << "m4 zeroed:\n";
    printMat(m4);
}