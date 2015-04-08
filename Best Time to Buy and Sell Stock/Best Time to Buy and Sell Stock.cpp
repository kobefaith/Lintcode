class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max;
        int min;
        if (prices.empty()){
            return 0;
        }
        return divde(prices,0,prices.size()-1,max,min);
    }
    int divde(vector<int> &prices,int beg,int end,int &max,int &min){
        int maxl = INT_MIN;
        int maxr = INT_MIN;
        int minl = INT_MAX;
        int minr = INT_MAX;
        if (beg == end ){
            max = min = prices[beg];
            return 0;
        }
        if (beg == end - 1){
            max = (prices[beg] > prices[end]) ?prices[beg] : prices[end];
            min = (prices[beg] > prices[end]) ?prices[end] : prices[beg];
           if((prices[end] - prices[beg]) >0){
               return prices[end] - prices[beg];
           }else{
               return 0;
           }
           
        }
        int mid = beg + (end - beg)/2;
        int resl = divde(prices,beg,mid-1,maxl,minl);
        int resr = divde(prices,mid,end,maxr,minr);
        max = (maxl > maxr)? maxl : maxr;
        min = (minl < minr)? minl : minr;
        resl = (resl < resr)? resr : resl;
        return (resl < (maxr-minl))? (maxr-minl) : resl;
    }
};