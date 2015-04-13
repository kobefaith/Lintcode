class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); i++){
            if (min > prices[i]){
                min = prices[i];
            }
            if (max_profit < (prices[i] - min)){
                max_profit = prices[i] - min;
            }
        }
        return max_profit;
    }
};

