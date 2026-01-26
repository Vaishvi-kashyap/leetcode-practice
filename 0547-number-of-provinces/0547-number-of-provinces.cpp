class Solution {
public:
    void dfs(vector<int> adj[], int V, vector<bool>& visited, int src) {
        visited[src] = true;
        for (auto it : adj[src]) {
            if (!visited[it])
                dfs(adj, V, visited, it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, V, visited, i);
            }
        }
        return count;
    }
};