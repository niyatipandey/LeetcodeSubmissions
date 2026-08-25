class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if( power == 0){
            return 1;
        }
        if(power == 1){
            return x;
        }
        if(power < 0){
            x = 1/x;
            power = -power;
        }
        if(power%2 == 0){
            double posCal = myPow(x,power/2);
            return  posCal*posCal;
        }
        double negCal = myPow(x,power/2);
        return x* negCal * negCal;
    }
};