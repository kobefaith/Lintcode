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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.empty() || preorder.empty()){
            return NULL;
        }
        
        TreeNode *root;
        root = ConstructBinaryTree(preorder,inorder,0,inorder.size(),0);
        
        return root;
    }
    TreeNode *ConstructBinaryTree(vector<int> &preorder, vector<int> &inorder,int ibeg,int ilen,int pbeg){
        if (ilen == 0){
            return NULL;
        }
        int r_index = ibeg;
        TreeNode *left;
        TreeNode *right;
        for (r_index; r_index < ibeg+ilen; r_index++){
            if (inorder[r_index] == preorder[pbeg]){
                break;
            }
        }
        TreeNode *root = new TreeNode(inorder[r_index]);
        left = ConstructBinaryTree(preorder,inorder,ibeg,r_index - ibeg,pbeg+1);
        right = ConstructBinaryTree(preorder,inorder,r_index+1,ibeg+ilen-1 - r_index,pbeg+1+r_index - ibeg);
        root->left = left;
        root->right = right;
        
        return root;
    }
};