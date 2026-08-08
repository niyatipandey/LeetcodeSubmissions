class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int i=0;
        int j=0;
        int n = fruits.size();
        int count=0;

        while(i<n){
            if(j == n){
                i++;
                j =0;
            }
            else if(fruits[i] <= baskets[j]){
                count++;
                i++;
                baskets[j] =0;
                j=0;
            }else{
                j++;
            }
        }
        return n-count;

    }
};