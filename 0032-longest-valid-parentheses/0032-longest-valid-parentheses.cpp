class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen =0;
        int left =0;
        int right =0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                left++;
            }else if(s[i]== ')'){
                right++;
            }

            if(left == right){
                maxLen = max(maxLen,2*right);
            }
            else if(right > left){
                left =0;
                right =0;
            }
        }
        left =right =0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '('){
                left++;
            }else if(s[i]== ')'){
                right++;
            }

            if(left == right){
                maxLen = max(maxLen,2*right);
            }
            else if(right < left){
                left =0;
                right =0;
            }
        }
        return maxLen;
    }
};