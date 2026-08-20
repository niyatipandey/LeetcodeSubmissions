class Solution {
public:
    string makeGood(string s) {
        string result;
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(!st.empty()){
                char top = st.top();
                if(tolower(top) == tolower(s[i]) && top != s[i]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};