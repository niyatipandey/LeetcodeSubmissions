class Solution {
public:
    int isPalindromeCheck(string& s,int left,int right,int count){
        while(left>=0 && right< s.length() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }

        return count;
    }
    int countSubstrings(string s) {
        if(s.length() < 2){
            return s.length();
        }

        int count = 0;

        for(int i=0;i<s.length();i++){
            count += isPalindromeCheck(s,i,i,0);
            count += isPalindromeCheck(s,i,i+1,0);

        }
        return count;
        
    }
};