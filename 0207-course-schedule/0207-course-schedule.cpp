class Solution {
public:
    bool isCycleDFS(int src, vector<vector<int>>& edge, vector<bool>& vis,
                    vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;
        for (int i = 0; i < edge.size(); i++) {
            int v = edge[i][0];
            int u = edge[i][1];
            if (u == src) {
                if (!vis[v]) {
                    if (isCycleDFS(v, edge, vis, recPath))
                        return true;
                } else if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edge) {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, edge, vis, recPath))
                    return false;
            }
        }
        return true;
    }
};