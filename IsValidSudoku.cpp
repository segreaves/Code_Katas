#include <iostream>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
    bool rows[9][10] = {};
    bool cols[9][10] = {};
    bool grids[9][10] = {};
    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            // Skip .
            if (board[r][c] == '.') continue;
            int num{ board[r][c] - '0' };
            // Check for repetitions in row
            if (rows[r][num])
                return false;
            else rows[r][num] = true;
            // Check for repetitions in col
            if (cols[c][num])
                return false;
            else cols[c][num] = true;
            // Check for repetitions in grid
            int grid_r{ r / 3 };
            int grid_c{ c / 3 };
            int grid_index{ (grid_r * 3 + grid_c) };
            if (grids[grid_index][num])
                return false;
            else grids[grid_index][num] = true;
        }
    }

    return true;
}

int main()
{
    std::vector<std::vector<char>> ex1
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << "Should be 1: " << isValidSudoku(ex1) << "\n";

    std::vector<std::vector<char>> ex2
    {
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    };
    std::cout << "Should be 0: " << isValidSudoku(ex2) << "\n";
}