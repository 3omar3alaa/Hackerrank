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
        this can be solved using 2 stacks
        where a each stack pushes into the other until it's NULL
        Right stack -> push node -> right first then node -> left
        Left stack -> push node -> left first then node -> right
        */
        vector<vector<int>> result;
        vector<int> level;
        if(root == NULL) return result;
        stack<TreeNode*> right_stack;
        stack<TreeNode*> left_stack;

        right_stack.push(root);
        while(!right_stack.empty() || !left_stack.empty()){
            // i know that the base condition is that the right stack is not empty
            TreeNode* node = NULL;
            while(!right_stack.empty()){
                node = right_stack.top();
                right_stack.pop();
                if(node -> left != NULL) left_stack.push(node->left);
                if(node -> right != NULL) left_stack.push(node->right);
                level.push_back(node -> val);
            }
            
            if(level.size()){             
                result.push_back(level);
                level.resize(0);   
            }
            
            while(!left_stack.empty()){
                node = left_stack.top();
                left_stack.pop();
                if(node -> right != NULL) right_stack.push(node->right);
                if(node -> left != NULL) right_stack.push(node->left);                
                level.push_back(node -> val);
            }
            
            if(level.size()){             
                result.push_back(level);
                level.resize(0);   
            }
        }        
        return result;
    }
};