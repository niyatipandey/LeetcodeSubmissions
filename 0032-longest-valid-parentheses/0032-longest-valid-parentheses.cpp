class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0;
        }
        stack<int>st;
        int len =0;
        st.push(-1);

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int top = st.top();
                    len = max(len , i -top);
                }
            }
        }
        return len;
    }
};