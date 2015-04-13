class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int m = prices.size();
        if (m < 2){
            return 0;
        }
        vector<int> left(m,0);
        vector<int> right(m,0);
        int min = INT_MAX;
        int max = INT_MIN;
        int max_profit = 0;
        for (int i = 0; i < m; i++){
            if (prices[i] < min){
                min = prices[i];
            }
            left[i] = prices[i] - min;
        }
        for (int i = m-1; i >= 0; i--){
            if (prices[i] > max){
                max = prices[i];
            }
            max_profit = ((max - prices[i]) > max_profit) ? (max - prices[i]) : max_profit;
            right[i] = max_profit;
        }
        max_profit = 0;
        for (int i = 0; i < m-1 ;i++){
            if ((left[i] + right[i+1]) > max_profit){
                max_profit = left[i] + right[i+1];
            }
        }
        return max_profit > right[0] ? max_profit : right[0];
        
    }
};