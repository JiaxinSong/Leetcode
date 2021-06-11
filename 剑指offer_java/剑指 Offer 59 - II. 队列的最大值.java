class MaxQueue {
    Queue<Integer> q;
    Deque<Integer> d;

    public MaxQueue() {
        q=new LinkedList<>();
        d=new LinkedList<>();
    }
    
    public int max_value() {
        if(d.isEmpty()) return -1;
        return d.peekFirst();
    }
    
    public void push_back(int value) {
        while(!d.isEmpty()&& d.peekLast()<value){
            d.pollLast();
        }
        d.addLast(value);
        q.add(value);
    }
    
    public int pop_front() {
        if(q.isEmpty()) return -1;
        int ans=q.poll();
        if(ans==d.peekFirst()) d.poll();
        return ans;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
