class CQueue {

public:
    stack<int> s1, s2;
    CQueue() {
        while(!s1.empty())s1.pop();
        while(!s2.empty())s2.pop();
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(!s2.empty()){
            int res = s2.top();
            s2.pop();
            return res;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        if(!s2.empty()){
            int res = s2.top();
            s2.pop();
            return res;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
