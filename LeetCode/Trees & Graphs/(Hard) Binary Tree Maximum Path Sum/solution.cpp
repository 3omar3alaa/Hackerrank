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
    // variable to store max value in a sub tree
    // so to hold the value if the max value is in a sub tree that doesnt include the root node
    int max_val = INT_MIN;
    
    int max_gain(TreeNode* root){        
        if(root == NULL) return 0;
        
        int right = max(max_gain(root -> right), 0);
        int left = max(max_gain(root -> left), 0);
        
        max_val = max(max_val, right + left + root -> val);
        
        // just return a single path
        return root -> val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        return max(max_val, max_gain(root));
    }
};