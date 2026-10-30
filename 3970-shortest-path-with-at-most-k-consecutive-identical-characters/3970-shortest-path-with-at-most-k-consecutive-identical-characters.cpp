class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        priority_queue<p, vector<p>, greater<p>> q;
        vector<vector<int>> res(n, vector<int>(k + 1, INT_MAX));
        res[0][1] = 0;
        q.push({0, {0, 1}});

        while (!q.empty()) {
            int node = q.top().second.first;
            int d = q.top().first;
            int cnt = q.top().second.second;

            q.pop();

            if (node == n - 1) return res[n - 1][cnt];
            
            if (d > res[node][cnt]) continue;


            for (auto v : adj[node]) {
                int adjNode = v.first;
                int wt = v.second;
                int newCnt = (labels[node] == labels[adjNode]) ? cnt + 1 : 1;
                if (newCnt > k) continue;

                if (d + wt < res[adjNode][newCnt]) {
                    res[adjNode][newCnt] = d + wt;
                    q.push({d + wt, {adjNode, newCnt}});
                }
            }
        }
        return -1;
    }
};