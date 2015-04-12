class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int xor_result = 0;
        int flag;
        vector<int> re(2,0);
        for (int i = 0; i < A.size(); i++){
            xor_result ^= A[i];
        }
        flag = xor_result-(xor_result & (xor_result-1));
        for ( int i = 0; i < A.size(); i++){
            if (flag & A[i]){
                re[0] ^= A[i];
            }else{
                re[1] ^= A[i];
            }
        }
        return re;
    }
};
