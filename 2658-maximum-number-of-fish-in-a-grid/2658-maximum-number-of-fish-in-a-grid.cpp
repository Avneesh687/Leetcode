class Solution {
public:
    int n, m;
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c];
        grid[r][c] = 0;

        queue<pair<int, int>> q;
        q.push({r, c});

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                    grid[newRow][newCol] > 0) {

                    sum += grid[newRow][newCol];
                    grid[newRow][newCol] = 0;
                    q.push({newRow, newCol});
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int fishes = bfs(grid, i, j);
                    res = max(res, fishes);
                }
            }
        }
        return res;
    }
};