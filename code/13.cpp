#include <bits/stdc++.h>

using namespace std;

int maxValue(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 1; i < n; i++)
        grid[0][i] += grid[0][i - 1];
    for (int j = 1; j < m; j++)
    {
        grid[j][0] += grid[j - 1][0];
    }
    for (int p = 1; p < m; p++)
    {
        for (int q = 1; q < n; q++)
        {
            grid[p][q] += max(grid[p][q - 1], grid[p - 1][q]);
        }
    }
    return grid[m - 1][n - 1];
}