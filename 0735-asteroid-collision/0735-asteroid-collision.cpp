class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<bool>alive(n,true);

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] <0){
                if(st.top() < -(asteroids[i])){
                    st.pop();
                }else if(st.top() > -(asteroids[i])){
                    alive[i] = false;
                    break;
                }else{
                    st.pop();
                    alive[i] = false;
                    break;
                }
            }
            if(alive[i]){
                st.push(asteroids[i]);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};