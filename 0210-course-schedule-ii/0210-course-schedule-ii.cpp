class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            res.push_back(src);
            for (int neighbor : adj[src]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (res.size() == V)
            return res;
        return {};
    }
};