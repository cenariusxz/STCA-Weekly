class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, m;
    MinStack() {
        while(!s.empty())s.pop();
        while(!m.empty())m.pop();
    }
    
    void push(int x) {
        if(s.empty())m.push(x);
        else m.push(std::min(x, m.top()));
        s.push(x);
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
