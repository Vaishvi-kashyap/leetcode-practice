class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];

            adj[u].push_back({v, d});
        }

        queue<pair<int, pair<int, int>>> q; //{stops,{node,dist}}
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (cost + wt < dist[v] && stops <= k) {
                    dist[v] = cost + wt;
                    q.push({stops + 1, {v, cost + wt}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};