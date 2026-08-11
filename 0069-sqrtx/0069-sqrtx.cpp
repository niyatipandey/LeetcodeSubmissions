class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        int left = 0;
        int right = x/2;

        while(left <= right){
            long long mid = left + (right-left)/2;
            long long sq = mid*mid;

            if(sq == x){
                return mid;
            }else if(sq < x){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return right;
    }
};