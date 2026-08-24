class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0;
        }
        stack<int>st;
        st.push(-1);
        int maxLen =0;

        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len = i - st.top();
                    maxLen = max(maxLen, len);
                }
            }else{
                st.push(i);
            }
        }
        return maxLen;
    }
};