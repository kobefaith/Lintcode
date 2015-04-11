class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int max = 0;
        vector<vector<int>> f(m+1,vector<int>(n+1,0));
        for (int i = 1; i <= m; i++ ){
            for (int j = 1; j <= n; j++){
                if (A[i-1] == B[j-1]){
                    f[i][j] = f[i-1][j-1] + 1;
                    if (max < f[i][j]){
                        max = f[i][j];
                    }
                }else{
                    f[i][j] = 0;
                }
            }
        }
        return max;
    }
};

