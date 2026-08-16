class Solution {
public:
    bool func(int day , vector<int>& bloomDay, int m, int k){
        int bouq = 0;
        int count =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                count++;
                if(count == k){
                    bouq++;
                    count =0;
                }
            }else{
                count =0;
            }
        }
        return bouq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m*k > n){
            return -1;
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(int i=0;i<n;i++){
            if(minVal > bloomDay[i]){
                minVal = bloomDay[i];
            }
        }
        for(int i=0;i<n;i++){
            if(maxVal < bloomDay[i]){
                maxVal = bloomDay[i];
            }
        }

        int low =minVal;
        int high = maxVal;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(func(mid,bloomDay,m,k)){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};