class MyStack {
public:
    queue<int>dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push(x);
        int n = dq.size();
        for(int i=0;i<n-1;i++){
            int x = dq.front();
            dq.pop();
            dq.push(x);
        }
    }
    
    int pop() {
        if(dq.empty()){
            return -1;
        }
        int x = dq.front();
        dq.pop();
        return x;
    }
    
    int top() {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }
    
    bool empty() {
        if(dq.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */