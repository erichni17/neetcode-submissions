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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {}; 
        vector<int> res; 
        int lvl = 0; 
        queue<TreeNode*> q; 

        q.push(root); 

        while (!q.empty()) {
            vector<TreeNode*> level; 
            int size = q.size(); 

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop(); 
                if (curr) {
                    level.push_back(curr); 
                    if (curr->left) q.push(curr->left); 
                    if (curr->right) q.push(curr->right); 
                }
            }
            TreeNode* rightMost = level[level.size() - 1]; 
            res.push_back(rightMost->val); 
        }

        return res; 
    }
};
