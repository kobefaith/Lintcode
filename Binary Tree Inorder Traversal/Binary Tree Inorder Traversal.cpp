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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int > result;
        if (root == NULL)
            return result;
        vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(),left.begin(),left.end());
        result.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(),right.begin(),right.end());
        return result;
    }
};