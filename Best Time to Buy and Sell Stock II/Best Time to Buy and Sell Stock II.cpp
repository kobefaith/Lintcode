class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        int end = 0;
        int beg = 0;
        if (prices.size() == 0 || prices.size() == 1){
            return 0;
        }
        prices.push_back(INT_MIN);
        for (int i = 0; i < prices.size()-1; i++){
            if (prices[i+1] < prices[i]){
                if (end > beg){
                    result += prices[end] - prices[beg];
                }
                beg = i+1;
            }else if (prices[i+1] > prices[i]){
                end = i+1;
            }
        }
        return result;
    }
};