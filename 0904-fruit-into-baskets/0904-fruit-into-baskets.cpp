class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int distinct =0;
        int i =0;
        int j =0;
        unordered_map<int,int>freq;
        int len =0;

        int n = fruits.size();
        while(j<n){
            if(freq[fruits[j]] == 0){
                distinct++;
            }
            freq[fruits[j]]++;
            while(distinct > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0){
                    distinct --;
                }
                i++;
            }
            if(distinct <= 2){
                len = max(len , j-i+1);
            }
            j++;
        }
        return len;
    }
};