class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
         vector<vector<int> > result;
         sort(S.begin(),S.end());
         vector<int> temp;
         dfs(S,result,temp,0);
         return result;
    }
    void dfs(vector<int> &S,vector<vector<int> > &result,vector<int> temp,int turn){
        if(turn == S.size()){
            result.push_back(temp);
            return;
        }
        dfs(S,result,temp,turn+1);
        temp.push_back(S[turn]);
        dfs(S,result,temp,turn+1);
        temp.pop_back();
    }
};