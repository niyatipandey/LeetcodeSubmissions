class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        vector<bool>alive(asteroids.size(),true);

        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && st.top() >0 && asteroids[i] <0){
                if(st.top() < -(asteroids[i])){
                    st.pop();
                }else if(st.top() == -(asteroids[i])){
                    st.pop();
                    alive[i] =false;
                    break;
                }else{
                    alive[i]=false;
                    break;
                }
            }
            if(alive[i]){
                st.push(asteroids[i]);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};