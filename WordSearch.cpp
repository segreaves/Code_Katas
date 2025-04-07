#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int pos)
{
    if (i < 0 || i >= board.size() ||
        j < 0 || j >= board[0].size() ||
        pos >= word.size()) return false;
    char c{ board[i][j] };
    if (c == '#' || c != word[pos]) return false;
    if (pos == word.size() - 1 && c == word[pos]) return true;

    pos++;
    board[i][j] = '#';
    // Check all 4 directions (must reset the board before returning or the original will be modified permanently)
    if (dfs(board, word, i + 1, j, pos))
    {
        board[i][j] = c;
        return true;
    }
    if (dfs(board, word, i - 1, j, pos))
    {
        board[i][j] = c;
        return true;
    }
    if (dfs(board, word, i, j + 1, pos))
    {
        board[i][j] = c;
        return true;
    }
    if (dfs(board, word, i, j - 1, pos))
    {
        board[i][j] = c;
        return true;
    }

    return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (dfs(board, word, i, j, 0)) return true;
    return false;
}

int main()
{
    std::vector<std::vector<char>> board{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    std::cout << "Should be 1: " << exist(board, "ABCCED") << std::endl;
    std::cout << "Should be 1: " << exist(board, "SEE") << std::endl;
    std::cout << "Should be 0: " << exist(board, "ABCB") << std::endl;
}