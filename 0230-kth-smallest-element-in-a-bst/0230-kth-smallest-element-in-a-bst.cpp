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
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root->left) {
            int left1 = kthSmallest(root->left, k);
            if (left1 != -1)
                return left1;
        }
        if (order + 1 == k) {
            return root->val;
        }
        order += 1;
        if (root->right) {
            int right1 = kthSmallest(root->right, k);
            if (right1 != -1)
                return right1;
        }
        return -1;
    }
};