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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root-> left, root -> right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(right == NULL || left == NULL)
            return right == left;
        if(right -> val != left -> val)
            return false;
        return isSymmetric(left -> left, right -> right) && isSymmetric(left -> right, right -> left);
    }
    /*void inOrder(TreeNode* root, vector<TreeNode*> & vec){
        if (root == NULL){
            vec.push_back(NULL);
            return;
        }
        if(root -> left == NULL) vec.push_back(NULL);
        else inOrder(root -> left, vec);
        vec.push_back(root);
        if(root -> right == NULL) vec.push_back(NULL);
        else inOrder(root -> right, vec);
    }
        
    void mirrorInOrder(TreeNode* root, vector<TreeNode*> & vec){
        if (root == NULL){
            vec.push_back(NULL);
            return;
        }
        if(root -> right == NULL) vec.push_back(NULL);
        else inOrder(root -> right, vec);
        vec.push_back(root);
        if(root -> left == NULL) vec.push_back(NULL);
        else inOrder(root -> left, vec);
        
    }
    bool isSymmetric(TreeNode* root) {
        // make inorder traversal to left sub tree
        // make opposite of inorder traversal to right sub tree
        // compare both
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        inOrder(root -> left, left);
        mirrorInOrder(root -> right, right);
        if(left.size() != right.size())
            return false;
        for(int i = 0; i < left.size(); i++)
        {
            if(right[i] == NULL) cout << "null ";
            else cout << right[i] -> val << " ";
        }
        cout << endl;
        for(int i = 0; i < left.size(); i++)
        {
            if(left[i] == NULL) cout << "null ";
            else cout << left[i] -> val << " ";
        }
        for(int i = 0; i < left.size(); i++){
            // cout << left[i] << " ";
            if(left[i] == NULL && right[i] != NULL)
                return false;
            if(left[i] != NULL && right[i] == NULL)
                return false;            
            if(left[i] != NULL && right[i] != NULL){
                if(left[i]->val != right[i]->val)
                    return false;
            }
        }
        /*cout << endl;
        for(int i = 0; i < left.size(); i++){
            cout << right[i] << " ";
        }
        return true;  
        
    }*/
};