class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<bool>inValid(s.length(),false);

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    inValid[i] = true;
                }
            }
        }
        while(!st.empty()){
            int x = st.top();
            inValid[x] = true;
            st.pop();
        }
        string res = "";
        for(int i=0;i<s.length();i++){
            if(!inValid[i]){
                res += s[i];
            }
        }
        return res;

    }
};