class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if(power == 0){
            return 1;
        }
        if(power == 1){
            return x;
        }
        if(power < 0){
            x = 1/x;
            power = -power;
        }
        if( power % 2 == 0){
            double even = myPow(x,power/2);
            return even * even;
        }
        double odd = myPow(x,power/2);
        return x * odd * odd;
    }
};