class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<int>freq(26,0);
        vector<bool>visited(26,false);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']--;
            if(!st.empty()){
                if(visited[s[i]-'a']){
                    continue;
                }
                while(!st.empty() && st.top() > s[i] && freq[st.top()-'a'] >0){
                    visited[st.top()-'a'] = false;
                    st.pop();
                }
                if(!visited[s[i]-'a']){
                    st.push(s[i]);
                    visited[s[i]-'a']= true;
                }
            }else{
                st.push(s[i]);
                visited[s[i]-'a'] = true;
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};