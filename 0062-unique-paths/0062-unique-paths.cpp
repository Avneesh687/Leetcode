class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 0;
        }
        if (r == m - 1 && c == n - 1) {
            return 1;
        }
        if (dp[r][c] != 0)
            return dp[r][c];

        int right = dfs(r + 1, c, m, n);
        int left = dfs(r, c + 1, m, n);

        return dp[r][c] = left + right;
    }
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        return dfs(0, 0, m, n);
    }
};