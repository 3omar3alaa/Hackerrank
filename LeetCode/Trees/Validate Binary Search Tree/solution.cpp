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
    void getInOrderBST(TreeNode* root, vector<int> * Arr){        
        if(root == NULL)
            return;
        getInOrderBST(root->left, Arr);
        Arr->push_back(root -> val);
        getInOrderBST(root->right, Arr);
    }
    
    bool isValidBST(TreeNode* root) {
        /*if(root == NULL)
            return true;
        if(root -> left && root -> left -> val >= root -> val)
            return false;
        if(root -> right && root -> right -> val <= root -> val)
            return false;
        
        return isValidBST(root -> left) && isValidBST(root -> right);*/
        
        vector<int> inOrderArr; 
        getInOrderBST(root, & inOrderArr);
        for(int i = 1; i < inOrderArr.size(); i++){
            if(inOrderArr[i] <= inOrderArr[i-1])
                return false;
        }
        return true;
    }
};