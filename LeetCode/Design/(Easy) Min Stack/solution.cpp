class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> result;
    MinStack() {
        
    }
    
    void push(int val) {
        result.push_back(val);
    }
    
    void pop() {
        result.erase(result.end()-1);
    }
    
    int top() {
        return result[result.size() - 1];
    }
    
    int getMin() {
        return *min_element(result.begin(), result.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */