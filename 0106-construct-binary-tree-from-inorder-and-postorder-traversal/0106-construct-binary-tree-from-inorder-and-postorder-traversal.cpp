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
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder,
                       int& postIdx, int left, int right) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int idx = inorderSearch(inorder, postorder[postIdx], left, right);
        postIdx--;
        root->right = makeTree(inorder, postorder, postIdx, idx + 1, right);
        root->left = makeTree(inorder, postorder, postIdx, left, idx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        return makeTree(inorder, postorder, postIdx, 0, inorder.size() - 1);
    }
};