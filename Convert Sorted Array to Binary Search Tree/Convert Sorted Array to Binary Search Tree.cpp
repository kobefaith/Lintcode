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
    TreeNode *sortedArrayToBST(vector<int> &num) {
         if(num.size() == 0)
            return NULL;
            
         TreeNode *root ;
         root = buildBST(num,0,num.size());
         
         return root;
    }
    TreeNode *buildBST(vector<int> &num,int beg,int len){
        if (len == 0)
           return NULL;
           
        int mid = beg + len/2;
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left ;
        TreeNode *right ;
        left = buildBST(num,beg,mid-beg);
        right = buildBST(num,mid+1,beg+len-1-mid);
        root->left = left;
        root->right = right;
        
        return root;
    }
    
};