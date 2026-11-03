class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v, w});
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, {src, 0}});
        vector<vector<int>> res(n, vector<int>(k + 2, INT_MAX));
        res[src][0] = 0;
        while (!pq.empty()) {
            int node = pq.top().second.first;
            int cost = pq.top().first;
            int stops = pq.top().second.second;

            pq.pop();

            if (stops > k + 1)
                continue;

            if (node == dst)
                return cost;

            for (auto& v : adj[node]) {
                int adjNode = v.first;
                int adjCost = v.second;
                int newStop = stops + 1;

                if (newStop <= k + 1 && res[adjNode][newStop] > cost + adjCost) {
                    res[adjNode][newStop] = cost + adjCost;
                    pq.push({cost + adjCost, {adjNode, newStop}});
                }
            }
        }
        return -1;
    }
};