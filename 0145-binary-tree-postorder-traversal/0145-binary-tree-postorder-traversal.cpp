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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode*> s1;
        TreeNode* curr = root;
        TreeNode* lastVisted = NULL;
        while (curr != NULL || !s1.empty()) {
            while (curr != NULL) {
                s1.push(curr);
                curr = curr->left;
            }

            TreeNode* node = s1.top();

            if (node->right != NULL && lastVisted != node->right) {
                curr = node->right;
            } else {
                ans.push_back(node->val);
                lastVisted = node;
                s1.pop();
            }
        }
        return ans;
    }
};