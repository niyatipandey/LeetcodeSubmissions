class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int maxVal = 0;
        for(int i=1;i<prices.size();i++){
            int diff = prices[i] - minVal;
            maxVal = max(maxVal,diff);
            minVal = min(minVal,prices[i]);
        }
        return maxVal;
    }
};