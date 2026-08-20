class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int result =0;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int num = stoi(tokens[i]);
                st.push(num);
            }else if(tokens[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                result = x + y;
                st.push(result);

            }else if(tokens[i] == "-"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                result = y -x;
                st.push(result);

            }
            else if(tokens[i] == "*"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                result = x * y;
                st.push(result);

            }
            else if(tokens[i] == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                result = y / x;
                st.push(result);

            }
        }

        return st.top();


    }
};