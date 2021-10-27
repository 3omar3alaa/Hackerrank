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
    vector<TreeNode*> generateTreeRec(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        }
        
        // choose a root
        for(int i = start; i <= end; i++){
            // build left branch
            vector<TreeNode*> left = generateTreeRec(start, i - 1);
            
            // build right branch
            vector<TreeNode*> right = generateTreeRec(i + 1, end);
            
            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            vector<TreeNode*> result(1, NULL);
            return result;
        }
        return generateTreeRec(1, n);
    }
};