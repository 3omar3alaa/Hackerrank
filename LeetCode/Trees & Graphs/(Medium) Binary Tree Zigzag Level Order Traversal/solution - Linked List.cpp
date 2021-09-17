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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*
        Another solution using Linked List and a bool
        */
        vector<vector<int>> result;
        list<int> level;
        bool left_order = true;
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // NULL works as a delimeter to know that a level has finished
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL){
                if(left_order) level.push_back(node -> val);
                else level.push_front(node -> val);                
                if(node -> left != NULL) q.push(node->left);
                if(node -> right != NULL) q.push(node->right);                
            }
            else{
                result.push_back(vector<int>(level.begin(), level.end()));
                level.clear();
                if(!q.empty())
                    q.push(NULL);
                left_order = !left_order;
            }
        }        
        return result;
    }
};