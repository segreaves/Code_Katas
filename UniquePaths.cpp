#include <iostream>
#include <vector>

int uniquePaths_Recursive(int m, int n)
{
    if (m <= 0 || n <= 0) return 0;
    if (m == 1 || n == 1) return 1;
    return uniquePaths_Recursive(m, n - 1) + uniquePaths_Recursive(m - 1, n);
}

int uniquePaths_Dynamic(int m, int n)
{
    if (m <= 0 || n <= 0) return 0;
    if (m == 1 || n == 1) return 1;
    std::vector<std::vector<int>> n_paths(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++) n_paths[i][0] = 1;
    for (int j = 0; j < n; j++) n_paths[0][j] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            n_paths[i][j] = n_paths[i - 1][j] + n_paths[i][j - 1];
    return n_paths[m - 1][n - 1];
}

int main()
{
    std::cout << " - Recursive -" << std::endl;
    std::cout << "Should be 28: " << uniquePaths_Recursive(3, 7) << std::endl;
    std::cout << "Should be 3: " << uniquePaths_Recursive(3, 2) << std::endl;

    std::cout << " - Dynamic -" << std::endl;
    std::cout << "Should be 28: " << uniquePaths_Dynamic(3, 7) << std::endl;
    std::cout << "Should be 3: " << uniquePaths_Dynamic(3, 2) << std::endl;
}