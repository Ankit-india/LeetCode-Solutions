class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = 0;
        int maxProfit = prices.at(0);
        for(auto x: prices){
            maxProfit = min(x, maxProfit);
            int temp = x - maxProfit;
            minTillNow = max(temp,minTillNow);
        }
        return minTillNow;
    }
};