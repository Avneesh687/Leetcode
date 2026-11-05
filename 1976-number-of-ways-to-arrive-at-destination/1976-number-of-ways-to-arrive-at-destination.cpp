class Solution {
public:
    const int m = 1e9 + 7;
    typedef pair<long long, long long> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<p>> adj(n);
        int maxTime = 0;
        for (auto road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long> res(n, LLONG_MAX);
        pq.push({0, 0});
        res[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        while (!pq.empty()) {
            int node = pq.top().second;
            long long t = pq.top().first;

            pq.pop();

            for (auto& v : adj[node]) {
                int adjNode = v.first;
                long long at = v.second;

                if (at + t < res[adjNode]) {
                    ways[adjNode] = ways[node];
                    res[adjNode] = at + t;
                    pq.push({at + t, adjNode});
                } else if (at + t == res[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % m;
                }
            }
        }
        return ways[n - 1];
    }
};