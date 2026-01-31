class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<vector<int>> revAdj(V);
        vector<int> outDegree(V, 0);

        // build reverse graph and count outdegree
        for (int i = 0; i < V; i++) {
            for (int next : adj[i]) {
                revAdj[next].push_back(i);
                outDegree[i]++; // count outgoing edges
            }
        }

        queue<int> q;
        vector<int> ans;

        // push terminal nodes (outDegree == 0)
        for (int i = 0; i < V; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }

        // Kahn's BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int prev : revAdj[node]) {
                outDegree[prev]--;
                if (outDegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(ans.begin(), ans.end()); // LeetCode needs sorted
        return ans;
    }
};
