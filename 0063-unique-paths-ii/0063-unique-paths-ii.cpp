class Solution {
public:
    long long mod = 2 * 1e9;
    int m, n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 0;
        }
        if (r == m - 1 && c == n - 1) {
            return 1;
        }
        if (grid[r][c] == 1)
            return 0;

        if (dp[r][c] != 0)
            return dp[r][c];

        int right = dfs(grid, r, c + 1);
        int left = dfs(grid, r + 1, c);

        return dp[r][c] = (left + right) % mod;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        return dfs(obstacleGrid, 0, 0);
    }
};