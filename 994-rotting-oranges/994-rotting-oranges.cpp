class Solution
{
public:
    bool isVal(vector<vector<int>>& grid, int i, int j)
    {
        return (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1 ? 0 : 1);
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int total = 0;           // to count total no of oranges
        queue<pair<int, int>> q; // queue for implementing bfs

        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    if (grid[i][j] == 2)
                    {
                        q.push({i, j});
                    }
                    total++;
                }
            }
        }

        int count = q.size(), days = 0;
        //  BFS
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    if (isVal(grid, ci + dx[i], cj + dy[i]))
                    {
                        q.push({ci + dx[i], cj + dy[i]});
                        count++;
                        grid[ci + dx[i]][cj + dy[i]] = 2;
                    }
                }
            }
            if (q.size())
            {
                days++;
            }
        }
        return (count == total ? days : -1);
    }
};