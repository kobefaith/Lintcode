class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int result = triangle[0][0];
        vector<vector<int>> flag(m,vector<int>(n,0));
        flag[0][0] = triangle[0][0];
        for (int i = 1; i < m; i++){
            flag[i][0] = flag[i-1][0]+triangle[i][0];
        }
        for (int i = 1; i < m; i++){
            result = flag[i][0];
            for (int j = 1; j < triangle[i].size()-1; j++){
                int left = flag[i-1][j] + triangle[i][j];
                int right = flag[i-1][j-1] + triangle[i][j];
                flag[i][j] = (left < right) ? left : right;
                if (flag[i][j] < result){
                    result = flag[i][j];
                }
            }
            flag[i][triangle[i].size()-1] = flag[i-1][triangle[i].size()-2] + triangle[i][triangle[i].size()-1];
            if (flag[i][triangle[i].size()-1] < result){
                result = flag[i][triangle[i].size()-1];
            }
        }
        
        return result;
    }
};