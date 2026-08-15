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
    bool isBalanced(TreeNode* root) {
        if (balancedHelper(root) == -1) {
            return false; 
        }
        return true; 
    }
    int balancedHelper(TreeNode* root) {
        if (!root) return 0; 
        int leftDepth = balancedHelper(root->left); 
        int rightDepth = balancedHelper(root->right); 
        if (leftDepth == -1 || rightDepth == -1) return -1; 
        if (abs(leftDepth - rightDepth) > 1) return -1; 
        else {
            return max(leftDepth, rightDepth) + 1; 
        }
    }
};
