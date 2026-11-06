#include <iostream>
#include <vector>
#include <queue>


std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
{
    const int rows{ static_cast<int>(mat.size()) };
    const int cols{ static_cast<int>(mat[0].size()) };
    const int INF{ 10000 };// From the problem constraints

    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INF));

    std::queue<std::pair<int, int>> q;

    // Fill distances we already know and prepare the queue of zeros
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (mat[r][c] == 0)
            {
                dist[r][c] = 0;
                q.emplace(std::pair<int, int>{ r, c });
            }
        }
    }

    const std::vector<int> dr{ 1, -1, 0, 0 };
    const std::vector<int> dc{ 0, 0, 1, -1 };

    while(!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            const int nr = r + dr[dir];
            const int nc = c + dc[dir];
            
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

            if (dist[nr][nc] > dist[r][c] + 1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(std::pair<int, int>{ nr, nc });
            }
        }
    }

    return dist;
}

int main()
{
}