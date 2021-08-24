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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.empty() == false)        
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL){
                if(node -> left != NULL) q.push(node->left);
                if(node -> right != NULL) q.push(node->right);
                level.push_back(node -> val);
            }
            else{
                if(q.size() > 0)
                    q.push(NULL);
                result.push_back(level);
                level.resize(0);
            }                
        }
        return result;
    }
};