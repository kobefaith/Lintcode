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
    struct Result{
        int height;
        bool isbalanced;
    };
    bool isBalanced(TreeNode *root) {
        Result re;
        re = getdepth(root);
        return re.isbalanced;
        
    }
    Result getdepth(TreeNode *root){
        Result re;
        if (root == NULL){
            re.height = 0;
            re.isbalanced = true;
            return re;
        }
        Result left = getdepth(root->left);
        Result right = getdepth(root->right);
        if (left.isbalanced && right.isbalanced && abs(left.height - right.height)<=1){
            re.height = (left.height > right.height ? left.height:right.height)+1;
            re.isbalanced = true;
            return re;
        }
        re.height = (left.height > right.height ? left.height:right.height)+1;
        re.isbalanced = false;
        return re;
    }
};