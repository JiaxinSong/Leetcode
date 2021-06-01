/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */

 class MinStack {

    private Deque<Integer> stack;
    private Deque<Integer> mins;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new LinkedList<>();
        mins = new LinkedList<>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(mins.isEmpty()) mins.push(x);
        else mins.push(Math.min(mins.peek(), x));
    }
    
    public void pop() {
        stack.pop();
        mins.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return mins.peek();
    }
}


