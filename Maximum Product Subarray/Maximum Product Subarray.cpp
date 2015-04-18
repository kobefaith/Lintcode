class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        int max = nums[0];
        vector<vector<int>> flag(n,vector<int>(2,1));
        flag[0][0] = nums[0];
        flag[0][1] = nums[0];
        for (int i = 1; i < n; i++){
            if (flag[i-1][0] == 0 || flag[i-1][1] == 0){
                flag[i][0] = nums[i];
                flag[i][1] = nums[i];
            }else if (nums[i] < 0){
                if (flag[i-1][1] > 0){
                    flag[i][0] = nums[i];
                    flag[i][1] = nums[i] * flag[i-1][0];
                }else{
                    if (flag[i-1][0] > 0){
                        flag[i][0] = flag[i-1][1] * nums[i];
                        flag[i][1] = flag[i-1][0] * nums[i];
                    }else if (flag[i-1][0] < 0){
                        flag[i][0] = flag[i-1][1] * nums[i];
                        flag[i][1] = nums[i];
                    }
                }
            }else if (nums[i] > 0){
                if (flag[i-1][0] < 0){
                    flag[i][0] = nums[i];
                }else{
                    flag[i][0] = nums[i] * flag[i-1][0];
                }
                flag[i][1] = nums[i] * flag[i-1][1];
                
            }else{
                flag[i][0] = 0;
                flag[i][1] = 0;
            }
            if (flag[i][0] > max){
                max = flag[i][0];
            }
        }
        
        return max;
    }
};
