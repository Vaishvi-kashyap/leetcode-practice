class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<bool>& visited,
             vector<bool>& pathVisited, vector<int>& res,
             vector<int>& safeNode) {
        visited[src] = true;
        pathVisited[src] = true;
        safeNode[src] = 0;

        for (int neighbor : graph[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, pathVisited, res, safeNode)) {
                    safeNode[src] = 0;
                    return true;
                }
            } else if (pathVisited[neighbor]) {
                safeNode[src] = 0;
                return true;
            }
        }
        safeNode[src] = 1;
        pathVisited[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<int> safeNode(V, 0);
        vector<int> res;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, pathVisited, res, safeNode);
            }
        }
        for (int i = 0; i < V; i++) {
            if (safeNode[i] == 1)
                res.push_back(i);
        }
        return res;
    }
};