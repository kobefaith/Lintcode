class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int size = nums.size();
        vector<int> sum(size,0);
        vector<int> result;
        if (size == 1){
            result.push_back(0);
            result.push_back(0);
            return result;
        }
        unordered_map<int,int> map;
        int diff = INT_MAX;
        sum[0] = nums[0];
        map[sum[0]] = 0;
        for (int i = 1; i < size; i++){
            sum[i] = sum[i-1] + nums[i];
            if (map.find(sum[i]) != map.end()){
                result.push_back(map.find(sum[i])->second+1);
                result.push_back(i);
                return result;
            }
            map[sum[i]] = i;
        }
        sort(sum.begin(),sum.end());
        for (int i = 1; i < size; i++){
            if (sum[i] - sum [i-1] <= diff){
                diff = sum[i] - sum [i-1];
            }
        }
        for (int i = 1; i < size; i++){
          if (sum[i] - sum[i-1] == diff){
                if (map[sum[i-1]]+1 <= map[sum[i]]){
                    result.push_back(map[sum[i-1]]+1);
                    result.push_back(map[sum[i]]);
                }else if (map[sum[i]]+1 <= map[sum[i-1]]){
                    result.push_back(map[sum[i]]+1);
                    result.push_back(map[sum[i-1]]);
                }
                return result;
            }
        }
    }
};