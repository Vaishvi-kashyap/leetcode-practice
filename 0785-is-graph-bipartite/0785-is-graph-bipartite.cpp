class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, int orgColor,
             vector<int>& color) {
        color[src] = orgColor;

        for (auto neighbor : graph[src]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, graph, !orgColor, color))
                    return false;
            } else if (color[neighbor] == orgColor)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, graph, 0, color))
                    return false;
            }
        }
        return true;
    }
};