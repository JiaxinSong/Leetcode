class MovingAverage {

    int size,sum;
    Deque<Integer> q ;

    public MovingAverage(int size) {
        q=new LinkedList<Integer>();
        this.size=size;
    }
    
    public double next(int val) {
        if(q.size()==size){
            sum-=q.poll();
        }
        q.offer(val);
        sum+=val;
        return (double) sum/q.size();
    }
}


