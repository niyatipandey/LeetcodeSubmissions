class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int sign = 1;
        long long num =0;
        int result =0;

        for(int i=0;i<s.length();i++){

            if(isdigit(s[i])){
                num = num * 10 + (s[i]-'0');
            }
            else if(s[i] == '+'){
                result += num*sign;
                num =0;
                sign =1;
            }
            else if(s[i] == '-'){
                result += num*sign;
                num =0;
                sign =-1;
            }
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);

                result =0;
                sign = 1;
            }
            else if(s[i] == ')'){
                result += sign*num;
                num =0;

                int prevSign = st.top();
                st.pop();

                int prevVal = st.top();
                st.pop();

                result = prevVal + prevSign*result;
            }
        }
        result += sign*num;

        return result;
    }
};