class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int m = gas.size();
        for (int i = 0; i < m; i++){
            int j = i;
            int remain = 0;
            for ( j; j < i+ m; j++){
                if (remain >= 0){
                   remain += gas[j % m];
                   remain -= cost[j % m];
                } else{
                   break;
                }
            }
            if (j == i+m && remain >= 0 ){
               return i;
            }
        }
        return -1;
        
    }
};