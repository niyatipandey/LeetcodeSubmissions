class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>tt;

        for(int i=0;i<s.length();i++){
            if(s[i] == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(!tt.empty()){
                    tt.pop();
                }
            }
            else{
                tt.push(t[i]);
            }
        }

        string resultS = "";
        while(!st.empty()){
            resultS += st.top();
            st.pop();
        }
        string resultT = "";
        while(!tt.empty()){
            resultT += tt.top();
            tt.pop();
        }
        return resultS == resultT;

    }
};