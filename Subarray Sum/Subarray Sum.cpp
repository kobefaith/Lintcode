class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int,int> map;
        unordered_map<int,int>::const_iterator got;
        vector<int> result;
        int sum = 0;
        map[0] = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            got = map.find(sum);
            if (got == map.end()){
                map[sum] = i+1;
            }else{
                result.push_back(got->second);
                result.push_back(i);
                return result;
            }
        }
    }
};
