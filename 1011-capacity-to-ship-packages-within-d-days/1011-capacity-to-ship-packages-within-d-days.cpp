class Solution {
public:
    bool leastWeight(vector<int>& weights,int days,int mid){
        int days_needed = 1;
        int currentWeight = 0;
        for(int weight : weights){
            if(currentWeight + weight > mid){
                days_needed += 1;
                currentWeight =0;
            }
            currentWeight += weight;
        }
        return days_needed <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxVal = INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(maxVal < weights[i]){
                maxVal = weights[i];
            }
        }
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
        }
        int low = maxVal;
        int high = sum;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(leastWeight(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};