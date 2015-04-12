class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int count = 0;
        int index;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                index = nums[i];
                count++;
                continue;
            }else{
                if ( nums[i] == index){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return index;
    }
};
