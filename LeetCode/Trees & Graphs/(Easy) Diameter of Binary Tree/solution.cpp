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
    int max_path = INT_MIN;
    
    int getMaxDiamater(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = getMaxDiamater(root -> left);
        int right = getMaxDiamater(root -> right);
        
        max_path = max(max_path, left + right);
        
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return max(max_path, getMaxDiamater(root) - 1); 
    }
};