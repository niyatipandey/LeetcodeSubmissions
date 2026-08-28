class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open =0;
        int close =0;
        int i=0;

        while( i < s.length()){
            if( s[i] == '('){
                open ++;
            }
            if(s[i] == ')'){
                close++;
            }

            if(open < close){
                s.erase(i,1);
                open = close =0;
            }else{
                i++;
            }
        }
        open = close =0;
        for(int i = s.length() -1; i>= 0;i--){
            if( s[i] == '('){
                open ++;
            }
            if(s[i] == ')'){
                close++;
            }

            if(open > close){
                s.erase(i,1);
                open = close =0;
            }
        }
        return s;
    }
};