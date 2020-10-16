//stack1负责入队列 stack2负责出队列 
//出队列时判断stack2是否为空 如果为空先把stack1全部倒入stack2
//pop stack2的顶部

class CQueue {
    stack<int> stack1,stack2;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int x=stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
        if(stack2.empty())return -1;
        else{
            int res=stack2.top();
            stack2.pop();
            return res;
        }
        
    }
};
