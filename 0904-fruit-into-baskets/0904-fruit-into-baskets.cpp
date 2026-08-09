class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i=0;
        int j=0;
        int distinct =0;
        int ans =0;
        vector<int>freq(n,0);

        while(j<n){
            if(freq[fruits[j]] == 0){
                distinct ++;
            }
            freq[fruits[j]]++;
            while(distinct > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0){
                    distinct--;
                }
                i++;

            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};