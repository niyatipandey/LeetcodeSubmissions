class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mpp;
        vector<bool>alreadyPresent(26,false);
        for(char c : s){
            mpp[c]++;
        }
        stack<char>st;
        string res ="";

        for(char c : s){
            mpp[c]--;
            if(!st.empty()){
                if(alreadyPresent[c-'a']){
                    continue;
                }else{
                    while(!st.empty() && st.top() > c && mpp[st.top()] > 0){
                        int x = st.top();
                        st.pop();
                        alreadyPresent[x-'a'] = false;
                        
                    }
                st.push(c);
                alreadyPresent[c-'a'] = true;
                }
                
            }else{
                st.push(c);
                alreadyPresent[c-'a']=true;
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};