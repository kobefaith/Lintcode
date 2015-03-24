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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> temp;
        queue<TreeNode*> qu;
        int turn =1;
        int size;
        if (root == NULL)
            return result;
        qu.push(root);
        while(!qu.empty()){
            size = qu.size();
            for(int i = 0; i < size; i++){
                temp.push_back(qu.front()->val);
                if(qu.front()->left != NULL)
                    qu.push(qu.front()->left);
                if(qu.front()->right != NULL)
                    qu.push(qu.front()->right);
                qu.pop();
            }
            if(turn %2 == 0){
                reverse(temp.begin(),temp.end());
            }
            result.push_back(temp);
            temp.clear();
            turn++;
        }
        
        return result;
    }
};