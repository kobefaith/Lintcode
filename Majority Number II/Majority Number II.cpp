class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int index1,index2;
        int count1 = 0,count2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (count1 == 0){
                index1 = nums[i];
            }
            if (count2 == 0){
                index2 = nums[i];
            }
            if (nums[i] == index1){
                count1++;
            }else if (nums[i] == index2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == index1){
                count1++;
            }else if (nums[i] == index2){
                count2++;
            }
        }
        if (count1 > count2){
            return index1;
        }else{
            return index2;
        }
    }
};
