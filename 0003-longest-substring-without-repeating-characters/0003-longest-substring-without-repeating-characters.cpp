class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0;
        int j=0;
        int count =0;
        vector<char>freq(256,0);
        int maxCount =0;

        while(j < n){
            freq[s[j]]++;

            while(freq[s[j]] > 1){
                freq[s[i]]--;
                count--;
                i++;
            }
            if(freq[s[j]] == 1){
                count++;
            }
            maxCount = max(maxCount,count);
            j++;
        }
        return maxCount;
    }
};