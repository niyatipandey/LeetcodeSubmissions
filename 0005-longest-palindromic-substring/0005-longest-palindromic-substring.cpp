class Solution {
public:
    string func(string& s, int i, int j){
        int n= s.length();
        while(i>=0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string res ="";
        for(int i=0;i<s.length();i++){
            string odd = func(s,i,i);
            string even = func(s,i,i+1);

            if(odd.length() > res.length()){
                res = odd;
            }
            if(even.length() > res.length()){
                res = even;
            }
        }
        return res;
    }
};