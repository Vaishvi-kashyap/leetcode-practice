/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q; // node*, {row,col}

        q.push({root, {0, 0}}); // ✅ Start BFS from root at (row=0, col=0)

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            m[col].push_back({row, node->val});

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        vector<vector<int>> res;
        for (auto it = m.begin(); it != m.end(); it++) {
            auto vec = it->second;
            sort(vec.begin(), vec.end());

            vector<int> column;
            for (auto p : vec)
                column.push_back(p.second);

            res.push_back(column);
        }
        return res;
    }
};