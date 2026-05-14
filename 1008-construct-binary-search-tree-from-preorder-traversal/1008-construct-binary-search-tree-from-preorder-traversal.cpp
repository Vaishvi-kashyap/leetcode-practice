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
    TreeNode* buildTree(vector<int>& preorder, int& idx, int upperBound) {
        if (idx == preorder.size() || preorder[idx] > upperBound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = buildTree(preorder, idx, root->val);
        root->right = buildTree(preorder, idx, upperBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return buildTree(preorder, idx, INT_MAX);
    }
};