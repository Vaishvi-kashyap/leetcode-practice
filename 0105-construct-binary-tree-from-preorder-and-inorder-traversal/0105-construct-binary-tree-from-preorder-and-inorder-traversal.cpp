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
    int inorderSearch(vector<int>& inorder, int root, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == root)
                return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int& preIdx, int left, int right) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int idx = inorderSearch(inorder, preorder[preIdx], left, right);
        preIdx++;
        root->left = buildTree(preorder, inorder, preIdx, left, idx - 1);
        root->right = buildTree(preorder, inorder, preIdx, idx + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return buildTree(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};