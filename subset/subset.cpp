class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int>> result;
    	vector<int> temp;
    	sort(nums.begin(),nums.end());
    	for(int i=0;i<=nums.size();i++){
    	    if(i == 0)
    	       result.push_back(temp);
    	   else
    	       dfs(nums,result,i,0,temp);
    	}
    	return result;
    }
    void dfs(vector<int> &nums,vector<vector<int>> &result,int k,int turn,vector<int> &temp){
        if(turn == k){
            result.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(temp.empty()){
                temp.push_back(nums[i]);
                dfs(nums,result,k,turn+1,temp);
                temp.pop_back();
            }else if(nums[i]>temp[turn-1]){
                temp.push_back(nums[i]);
                dfs(nums,result,k,turn+1,temp);
                temp.pop_back();
            }
        }
    }
    
    
};