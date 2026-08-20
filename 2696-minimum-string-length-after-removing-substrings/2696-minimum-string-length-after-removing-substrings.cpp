class Solution {
public:
    int minLength(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(!st.empty()){
                if(st.top() == 'A' && s[i] == 'B'){
                    st.pop();
                }
                else if(st.top() == 'C' && s[i] == 'D'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }

        string result ="";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result.length();
    }
};