class Solution {
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    int find(int i) {
        if (i == parent[i])
            return i;

        return parent[i] = find(parent[i]);
    }
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        parent = vector<int>(n);
        rank = vector<int>(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });
        int ans = 0;
        for(auto edge : edges){
            int x = edge[0];
            int y = edge[1];
            int w = edge[2];

            int xp = find(x);
            int yp = find(y);

            if(xp != yp){
                Union(x, y);
                ans += w;
            }
        }
        return ans;
    }
};