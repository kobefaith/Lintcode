class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int m = nums.size();
        vector<vector<int>> left(m,vector<int>(2,0));
        vector<vector<int>> right(m,vector<int>(2,0));
        int max ;
        int min ;
        int result = INT_MIN;
        left[0][0] = nums[0];
        left[0][1] = nums[0];
        right[m-1][0] = nums[m-1];
        right[m-1][1] = nums[m-1];
        for (int i = 1; i < m; i++){
	         if (left[i-1][0] > 0 ){
	         	left[i][0] = left[i-1][0] + nums[i];			
	         }else{
	         	left[i][0] = nums[i];			
	         }
	         if (left[i-1][1] > 0 ){			
	         	left[i][1] = nums[i];
	         }else{			
	         	left[i][1] = left[i-1][1] + nums[i];
	         }
	    }
        for (int i = m-2; i >= 0; i--){
        	if (right[i+1][0] > 0){
        		right[i][0] = right[i+1][0] + nums[i];			
        	}else{
        		right[i][0] = nums[i];			
        	}
        	if (right[i+1][1] > 0){			
        		right[i][1] = nums[i];
        	}else{			
        		right[i][1] = right[i+1][1] + nums[i];
        	}
        }
        max = right[m-1][0];
        min = right[m-1][1];
        for (int i = m-2; i >= 0; i--){
            if (right[i][0] > max){
                max = right[i][0];
            }else{
                right[i][0] = max;
            }
            if (right[i][1] < min){
                min = right[i][1];
            }else{
                right[i][1] = min;
            }
        }
        for (int i = 0; i < m-1; i++){
            if (abs(left[i][0] - right[i+1][0]) > result){
                result = abs(left[i][0] - right[i+1][0]);
            }
            if (abs(left[i][0] - right[i+1][1]) > result){
                result = abs(left[i][0] - right[i+1][1]);
            }
            if (abs(left[i][1] - right[i+1][0]) > result){
                result = abs(left[i][1] - right[i+1][0]);
            }
            if (abs(left[i][1] - right[i+1][1]) > result){
                result = abs(left[i][1] - right[i+1][1]);
            }
        }
        return result;
    }
};