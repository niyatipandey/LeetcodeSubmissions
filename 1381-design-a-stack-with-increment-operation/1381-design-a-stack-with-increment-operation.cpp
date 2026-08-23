class CustomStack {
public:
    vector<int>stack;
    vector<int>incVal;
    int index;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        index = -1;
        incVal.resize(maxSize);
    }
    
    void push(int x) {
        if(index == maxSize -1){
            return;
        }
        index++;
        stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty()){
            return -1;
        }
        int result = stack[index] + incVal[index];
        if(index > 0){
            incVal[index-1] += incVal[index];
        }
        incVal[index] = 0;
        index--;
        stack.pop_back();
        return result;
        
    }
    
    void increment(int k, int val) {
        if(index == -1){
            return;
        }
        int idx = min(k-1 , index);
        if(val >= 0){
            incVal[idx] += val;
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