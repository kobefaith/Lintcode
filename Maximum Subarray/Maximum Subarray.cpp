class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> f(n,0);
        int max = nums[0];
        f[0] = nums[0];
        for (int i = 1; i < n; i++){
            if (f[i-1] < 0){
                f[i] = nums[i];
            }else{
                f[i] = f[i-1] + nums[i];
            }
            if (max < f[i]){
                max = f[i];
            }
        }
        return max;
    }
};
