/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, root->val); 
    }
    int helper(TreeNode* root, int currMax) {
        int curr = 0; 
        if (!root) return curr; 
        if (root->val >= currMax) {
            curr++;
            currMax = root->val; 
        } 
        return curr + helper(root->left, currMax) + helper(root->right, currMax);
    }
};
