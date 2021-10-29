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
    bool traverse(TreeNode* root, int sum, int& target){
        if(root -> left == NULL && root -> right == NULL && sum + root -> val == target) return true;
        else if(root -> left == NULL && root -> right == NULL && sum + root -> val != target) return false;
        
        bool left = false;
        bool right = false;
        
        if(root -> left != NULL) left = traverse(root -> left, sum + root -> val, target);
        if(root -> right != NULL) right = traverse(root -> right, sum + root -> val, target);
        
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return traverse(root, 0, targetSum);
    }
};