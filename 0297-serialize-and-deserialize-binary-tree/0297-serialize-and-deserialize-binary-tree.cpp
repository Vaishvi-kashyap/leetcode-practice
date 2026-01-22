/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "null";

        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                ans += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                ans += "null,";
            }
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null")
            return NULL;
        vector<string> tokens;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < tokens.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (tokens[i] != "null") {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            if (i < tokens.size() && tokens[i] != "null") {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));