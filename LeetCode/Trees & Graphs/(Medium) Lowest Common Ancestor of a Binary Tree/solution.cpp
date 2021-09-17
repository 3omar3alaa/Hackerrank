/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findNodeDFS(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& found){
        if(root == NULL || found) return; 
        
        if(root == target){
            found = true;
        }
        else{
            findNodeDFS(root -> left, target, path, found);
            findNodeDFS(root -> right, target, path, found);
        }
        
        if(found) path.push_back(root);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        Solution is to make 2 vectors to hold the path from the node from the root using DFS
        then from the difference between the 2 vectors return the lowest common ancestor
        */ 
        
        vector<TreeNode*> firstPath;
        vector<TreeNode*> secondPath;
        bool found = false;
        findNodeDFS(root, p, firstPath, found);
        
        // if node p isn't found
        if(!found) return NULL;
        
        found = false;
        findNodeDFS(root, q, secondPath, found);
        // if node q isn't found
        if(!found) return NULL;
        
        TreeNode* result = NULL;
        int i = firstPath.size() - 1;
        int j = secondPath.size() - 1;
        while(i > 0 && j > 0){
            if(firstPath[i] == secondPath[j] && firstPath[i - 1] != secondPath[j - 1]){
                break;
            }
            i--;
            j--;
        }
        result = firstPath[i];
        return result;
    }
};