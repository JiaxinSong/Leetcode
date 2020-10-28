class MinStack {
public:
    stack<int> data,help;

    /** initialize your data structure here. */
    MinStack() {


    }
    
    void push(int x) {
        data.push(x);
        if(help.empty()||x<=help.top()) help.push(x);
        if(x>help.top()){
            
            help.push(help.top());
        }

    }
    
    void pop() {
        data.pop();
        help.pop();
    }
    
    int top() {
    return data.top();

    }
    
    int min() {
        return help.top();
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
