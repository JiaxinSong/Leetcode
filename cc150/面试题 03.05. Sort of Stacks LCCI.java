class SortedStack {
    Deque<Integer> minStack;
    Deque<Integer> tmp;

    public SortedStack() {
        minStack=new LinkedList<>();
        tmp=new LinkedList<>();
    }
    
    public void push(int val) {
        while(!minStack.isEmpty()&&minStack.peek()<val){
            tmp.push(minStack.pop());
        }
        minStack.push(val);
        while(!tmp.isEmpty()) minStack.push(tmp.pop());
    }
    
    public void pop() { 
        if(minStack.isEmpty()) return;
        minStack.pop();
    }
    
    public int peek() {
        if(minStack.isEmpty()) return -1;
        return minStack.peek();
    }
    
    public boolean isEmpty() {
        return minStack.isEmpty();
    }
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack obj = new SortedStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.isEmpty();
 */
