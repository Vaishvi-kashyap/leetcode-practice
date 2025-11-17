class Solution {
public:
    bool isCycleDFS(int src, vector<vector<int>>& graph, vector<bool>& vis,
                    vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int neighbor : graph[src]) {
            if (!vis[neighbor]) {
                if (isCycleDFS(neighbor, graph, vis, recPath))
                    return true;
            } else if (recPath[neighbor]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool>& vis, stack<int>& s,
                  vector<vector<int>>& graph) {
        vis[src] = true;

        for (int neighbor : graph[src]) {
            if (!vis[neighbor]) {
                topoSort(neighbor, vis, s, graph);
            }
        }

        s.push(src); // Push after processing all neighbors
    }

    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> graph(V);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]); // pre[1] -> pre[0]
        }

        // Cycle detection
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, graph, vis, recPath))
                    return {}; // Return empty array if cycle exists
            }
        }

        // Topological sort
        stack<int> s;
        vis.assign(V, false); // Reset visited array

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, vis, s, graph);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};