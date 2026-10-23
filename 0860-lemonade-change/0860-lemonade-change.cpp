class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int bill : bills){
            if(bill == 5){
                five++;
            }else if(bill == 10){
                if(five > 0){
                    five--;
                }else if(five == 0){
                    return false;
                }
                ten++;
            }else if(bill == 20){
                if(ten > 0 && five > 0){
                    five--;
                    ten--;
                }
                else if(five >= 3){
                    five -= 3;
                }else if(five < 3){
                    return false;
                }
            }
        }
        return true;
    }
};