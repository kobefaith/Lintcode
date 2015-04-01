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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()){
            return NULL;
        }
        TreeNode *root;
        root = ConstructBinaryTree(inorder,postorder,0,inorder.size(),0);
        return root;
    }
    TreeNode *ConstructBinaryTree(vector<int> &inorder, vector<int> &postorder,int ibeg,int ilen,int pbeg){
        if (ilen == 0){
            return NULL;
        }
        int r_index = ibeg;
        TreeNode *left;
        TreeNode *right;
        for (r_index; r_index < ibeg+ilen; r_index++){
            if (inorder[r_index] == postorder[pbeg+ilen-1]){
                break;
            }
        }
        TreeNode *root = new TreeNode(inorder[r_index]);
        if (r_index - ibeg > 0){
            left = ConstructBinaryTree(inorder,postorder,ibeg,r_index - ibeg,pbeg);
        }else{
            left = NULL;
        }
        if (ibeg+ilen-1 - r_index > 0){
            right = ConstructBinaryTree(inorder,postorder,r_index+1,ibeg+ilen-1 - r_index,pbeg+r_index-ibeg);
        }else{
            right = NULL;
        }
        root->left = left;
        root->right = right;
        return root;
    }
};