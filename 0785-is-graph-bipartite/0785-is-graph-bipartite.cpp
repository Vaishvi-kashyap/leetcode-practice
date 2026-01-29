class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, int V, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto neighbor : graph[curr]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = !color[curr];
                    q.push(neighbor);
                } else if (color[neighbor] == color[curr])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, V, color))
                    return false;
            }
        }
        return true;
    }
};