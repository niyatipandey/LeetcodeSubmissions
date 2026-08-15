class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq1(256,0);
        vector<int>freq2(256,0);
        if(t.empty()){
            return "";
        }

        int n = s.length();
        int m = t.length();

        for(int i=0;i<m;i++){
            freq1[t[i]]++;
        }

        int i=0;
        int j=0;
        int len =INT_MAX;
        int start = 0;
        int count =0;

        while(j < n){
            if(freq2[s[j]] < freq1[s[j]]){
                count++;
            }
            freq2[s[j]]++;

            while(count == m){
                if(len > j-i+1){
                    start = i;
                }
                len = min(len, j-i+1);
                freq2[s[i]]--;
                if(freq2[s[i]] < freq1[s[i]]){
                    count--;
                }
                i++;
            }
            j++;
        }
        if( len == INT_MAX){
            return "";
        }
        return s.substr(start,len);
    }
};