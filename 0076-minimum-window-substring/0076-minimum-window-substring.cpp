class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq1(256,0);
        vector<int>freq2(256,0);

        for(int i=0;i<t.length();i++){
            freq2[t[i]]++;
        }

        int count =0;
        int i=0;
        int j=0;
        int len = INT_MAX;
        int start =0;

        while(j < s.length()){
            freq1[s[j]]++;

            if(freq1[s[j]] <= freq2[s[j]]){
                count++;
            }

            while(count == t.length()){
                if(j-i+1 < len){
                    len = j-i+1;
                    start =i;
                }

                freq1[s[i]]--;
                if(freq1[s[i]] < freq2[s[i]]){
                    count--;
                }
                i++;
            }
            j++;
        }

        if(len == INT_MAX){
            return  "";
        }

        return s.substr(start,len);
    }
};