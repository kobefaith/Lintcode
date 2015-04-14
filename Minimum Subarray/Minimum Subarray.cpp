class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int min = nums[0];
        int m = nums.size();
        vector<int> sum(m,0);
        sum[0] = nums[0];
        for (int i = 1; i < m; i++){
            if (sum[i-1] >= 0){
                sum[i] = nums[i];
            }else{
                sum[i] = sum[i-1] + nums[i];
            }
            if (sum[i] < min){
                min = sum[i];
            }
        }
        return min;
    }
};

