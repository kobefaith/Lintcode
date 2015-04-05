class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if (len %2 == 1){
            return nums[len/2];
        }else{
            return nums[len/2-1];
        }
       
        
    }
};
