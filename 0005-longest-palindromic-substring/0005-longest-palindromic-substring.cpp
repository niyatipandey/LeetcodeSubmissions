class Solution {
public:
    string isPalindromeLen(string& s,int left,int right){
        while(left>=0 && right<s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-(left+1));
    }
    string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string result ="";

        for(int i=0;i<s.length();i++){

            string oddStr = isPalindromeLen(s,i,i);
            string evenStr = isPalindromeLen(s,i,i+1);

            if(oddStr.length() > result.length()){
                result = oddStr;
            }
            if(evenStr.length() > result.length()){
                result = evenStr;
            }
        }
        return result;
    }
};