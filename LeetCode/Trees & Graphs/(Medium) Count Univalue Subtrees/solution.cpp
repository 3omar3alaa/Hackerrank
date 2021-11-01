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
    int countRecursive(TreeNode* root){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;
        
        int left_count = countRecursive(root -> left);
        int right_count = countRecursive(root -> right); 
        
        int count = 0;
        if(root -> left != NULL && root -> right != NULL){
            if (root -> val == root -> left -> val && root -> val == root -> right -> val)
                count++;
            else root -> val = INT_MAX;
        }
        else if(root -> left == NULL && root -> right != NULL){
            if(root -> val == root -> right -> val) count++;
            else root -> val = INT_MAX;
        }
        else if(root -> left != NULL && root -> right == NULL){
            if(root -> val == root -> left -> val) count++;
            else root -> val = INT_MAX;
        }
        // change the root's val if it has diff values from its children
        // to overcome the problem [1,1,1,5,5,null,5]
        else{
            root -> val = INT_MAX;
        }
        
        return left_count+ right_count + count;
    }
    int countUnivalSubtrees(TreeNode* root) {
        return countRecursive(root);
    }
};