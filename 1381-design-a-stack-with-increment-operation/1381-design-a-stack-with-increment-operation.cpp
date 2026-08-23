class CustomStack {
public:
    stack<int>st;
    stack<int>st2;
    int maxiSize;
    CustomStack(int maxSize) {
        maxiSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxiSize){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int x = st.top();
        st.pop();
        return x;
    }
    
    void increment(int k, int val) {
        while(!st.empty()){
            int x = st.top();
            st.pop();
            st2.push(x);
        }

        while(k > 0 && !st2.empty()){
            int x = st2.top();
            st2.pop();
            st.push(x + val);
            k--;
        }
        while(!st2.empty()){
            int x = st2.top();
            st2.pop();
            st.push(x);
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */