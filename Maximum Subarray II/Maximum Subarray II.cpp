class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int m = nums.size();
        vector<int> left(m,0);
        vector<int> right(m,0);
        int max = INT_MIN;
        int flag ;
        left[0] = nums[0];
        right[m-1] = nums[m-1];
        for (int i = 1; i < m; i++){
            if (left[i-1] > 0 ){
                left[i] = left[i-1] + nums[i];
            }else{
                left[i] = nums[i];
            }
        }
        for (int i = m-2; i >= 0; i--){
            if (right[i+1] > 0){
                right[i] = right[i+1] + nums[i];
            }else{
                right[i] = nums[i];
            }
        }
        flag = right[m-1];
        for (int i = m-2; i >= 0; i--){
            if (right[i] > flag){
                flag = right[i];
            }else{
                right[i] = flag;
            }
        }
        for (int i = 0; i < m-1; i++){
            if ((left[i] + right[i+1]) > max){
                max = left[i] + right[i+1];
            }
        }
        return max;
    }
};
