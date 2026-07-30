class MinStack {
private: 
    stack<int> s; 
    stack<int> pre;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        int temp; 
        if (pre.empty()) temp = val; 
        else temp = min(val, pre.top()); 
        pre.push(temp); 
    }
    
    void pop() {
        s.pop();
        pre.pop(); 
    }
    
    int top() {
        return s.top(); 
    }
    
    int getMin() {
        return pre.top(); 
    }
};
