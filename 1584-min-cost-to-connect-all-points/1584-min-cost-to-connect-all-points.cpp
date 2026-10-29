class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<p>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<p, vector<p>, greater<p>> q;
        q.push({0, 0});
        vector<int> mst(n, 0);
        int cost = 0;
        while (!q.empty()) {
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();

            if (mst[node]) continue;
            mst[node] = 1;
            cost += wt;
            for (auto v : adj[node]) {
                int adjnode = v.first;
                int w = v.second;

                if (!mst[adjnode]) {
                    q.push({w, adjnode});
                }
            }
        }
        return cost;
    }
};