class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int i =0;
        int j=0;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<n;i++){
            freq2[s1[i]-'a']++;
        }

        while(j < m){
            freq1[s2[j]-'a']++;

            if(j-i+1 > s1.length()){
                freq1[s2[i]-'a']--;
                i++;
            }
            if(freq1 == freq2){
                return true;
            }

            j++;
        }
        return false;
    }
};