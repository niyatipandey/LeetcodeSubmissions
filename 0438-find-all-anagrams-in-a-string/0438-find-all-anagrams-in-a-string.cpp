class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>arr;
        int n = s.length();
        int i=0;
        int j=0;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<p.length();i++){
            freq1[p[i]-'a']++;
        }

        while(j<n){
            freq2[s[j]-'a']++;

            while(j-i+1 > p.length()){
                freq2[s[i]-'a']--;
                i++;
            }
            if(freq2 == freq1){
                arr.push_back(i);
            }
            j++;
        }
        return arr;
    }
};