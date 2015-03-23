/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int > result;
        if (root == NULL)
            return result;            
       
        vector<int> left = postorderTraversal(root->left);
        result.insert(result.end(),left.begin(),left.end());
        
        vector<int> right = postorderTraversal(root->right);
        result.insert(result.end(),right.begin(),right.end());
        
        result.push_back(root->val);
        
        return result;
        
    }
};