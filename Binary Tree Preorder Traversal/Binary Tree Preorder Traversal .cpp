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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int > result;
        if (root == NULL)
            return result;
            
        result.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        result.insert(result.end(),left.begin(),left.end());
        
        vector<int> right = preorderTraversal(root->right);
        result.insert(result.end(),right.begin(),right.end());
        
        return result;
    }
};