class Solution {
public:
    long long mod = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<int>>& grid, int r, int c, int dir) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 0;
        }
        if (r == m - 1 && c == n - 1) {
            return 1;
        }
        if (dp[r][c][dir] != -1)
            return dp[r][c][dir];
        if (grid[r][c] == 1) {
            if (dir == 0) {
                return dp[r][c][dir] = dfs(grid, r + 1, c, 1);
            } else {
                return dp[r][c][dir] = dfs(grid, r, c + 1, 0);
            }
        }

        int right = dfs(grid, r, c + 1, 0);
        int down = dfs(grid, r + 1, c, 1);

        return dp[r][c][dir] = (down + right) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return dfs(grid, 0, 0, 0);
    }
};