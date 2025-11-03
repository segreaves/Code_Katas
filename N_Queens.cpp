#include <iostream>
#include <vector>
#include <string>

bool isSafe(std::vector<std::string>& board, int row, int col)
{
    const int n = board.size();
    for (int r = row - 1; r >= 0; --r)
    {
        // Check for queens above
        if (board[r][col] == 'Q') return false;
        // Check for queens up-left
        if (const int c_l{ col - (row - r) }; c_l >= 0)
            if (board[r][c_l] == 'Q') return false;
        // Check for queens up-right
        if (const int c_r{ col + (row - r) }; c_r < n)
            if (board[r][c_r] == 'Q') return false;
    }
    return true;
}

void solve(std::vector<std::string> board, int row, std::vector<std::vector<std::string>>& ans)
{
    // Check if board is complete
    if (row == board.size())
    {
        ans.emplace_back(board);
        return;
    }

    // Solve row
    const int n = board.size();
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(board, row + 1, ans);
            board[row][col] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveQueens(int n)
{
    std::vector<std::vector<std::string>> ans;
    // Create empty board of size N
    std::vector<std::string> board(n, std::string(n, '.'));
    solve(board, 0, ans);
    return ans;
}

int main()
{
    solveQueens(4);
}