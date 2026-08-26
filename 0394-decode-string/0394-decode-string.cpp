class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        string finalStr = "";
        for(char c : s){
            if(c != ']'){
                st.push(c);
            }
            else{
                string res = "";
                string str = "";
                while(!st.empty() && st.top() != '['){
                    res += st.top();
                    st.pop();
                }
                st.pop();
                reverse(res.begin(),res.end());

                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int val = stoi(num);

                for(int i=0;i<val;i++){
                    str += res;
                }

                for(char ch : str){
                    st.push(ch);
                }
                
            }
        }
        while(!st.empty()){
            finalStr += st.top();
            st.pop();
        } 
        reverse(finalStr.begin(),finalStr.end());
        return finalStr;
    }
};