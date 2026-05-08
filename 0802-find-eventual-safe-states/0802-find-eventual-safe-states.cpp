class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<vector<int>> revAdj(V);
        vector<int> outDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                revAdj[it].push_back(i);
                outDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (auto it : revAdj[curr]) {
                outDegree[it]--;
                if (outDegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};