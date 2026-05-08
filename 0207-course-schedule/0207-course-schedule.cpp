class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[curr]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (cnt == V)
            return true;
        return false;
    }
};