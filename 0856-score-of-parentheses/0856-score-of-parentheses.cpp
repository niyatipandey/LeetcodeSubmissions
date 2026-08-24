class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char c : s){
            if(c == '('){
                st.push(0);
            }else{
                if(st.top() == 0){
                    st.pop();
                    st.top() += 1;
                }else{
                    int x = st.top();
                    st.pop();
                    st.top() += 2*x;
                }
            }
        }
        return st.top();
    }
};