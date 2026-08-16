class Solution {
public:
    bool func(int dis,vector<int>& dist, double hour ){
        double sumOfHour =0;
        for(int i=0;i<dist.size()-1;i++){
            sumOfHour += (dist[i] + dis -1)/dis;
        }
        sumOfHour += (double)dist.back()/dis;
        return sumOfHour <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1;
        int high = 1e7;
        int ans = -1;

        if(hour <= n-1){
            return -1;
        }

        while(low <= high){
            int mid = low + (high-low)/2;
            if(func(mid,dist,hour)){
                ans = mid;
                high =mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};