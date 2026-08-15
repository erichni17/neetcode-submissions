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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0; 
        inorder(root, k, result); 
        return result; 
    }

    void inorder(TreeNode* root, int& count, int& result) {
        if (!root || result != 0) return; 
        inorder(root->left, count, result);
        count--; 
        if (count == 0) {
            result = root->val; 
        }
        inorder(root->right, count, result); 
    }
};
