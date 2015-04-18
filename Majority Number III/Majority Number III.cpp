class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int,int> map;
        unordered_map<int,int> :: iterator index;
        unordered_map<int,int> :: iterator pos;
        int max = 0;
        int len = nums.size();
        int result;
        int size = 0;
        for (int i = 0; i < len; i++){
        	index = map.find(nums[i]);
        	if (index != map.end()){
        		index->second++;
        	}else {			
        		if (size == k-1){
        			for (pos = map.begin(); pos != map.end(); pos++){					
        				if (pos->second == 1){
        					pos->second = 0;
        					size--;						
        					continue;
        				}else if(pos->second > 1){
        					pos->second--;
        				}
        			}
        		}else if (size < k-1){
        			map[nums[i]] = 1;
        			size++;
        		}
        	}
        }	
        for (index = map.begin(); index != map.end(); index++){	
        	if (index->second == 0){
        		index->second = INT_MIN;
        	}else{
        		index->second = 0;
        	}
        }
        for (int i = 0; i < len; i++){
        	index = map.find(nums[i]);
        	if (index != map.end()){
        		index->second++;
        		if (index->second > max){
        			max = index->second;
        			result = index->first;
        		}
        	}
        }
        return result;
    }
};
