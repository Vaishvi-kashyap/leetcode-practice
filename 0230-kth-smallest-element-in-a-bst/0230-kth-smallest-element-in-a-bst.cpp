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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == NULL) {
                cnt++;
                if (cnt == k)
                    ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* ip = curr->left;
                while (ip->right != NULL && ip->right != curr)
                    ip = ip->right;
                if (ip->right == NULL) {
                    ip->right = curr;
                    curr = curr->left;
                } else {
                    ip->right = NULL;
                    cnt++;
                    if (cnt == k)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};