class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Queue<Integer> queue=new PriorityQueue<>((x,y)->(y-x));
        if(k==0) return new int[0];
        for(int num:arr){
            if(queue.size()<k) queue.add(num);
            else {
                if(queue.peek()>num) {
                    queue.poll();
                    queue.add(num);
                }
            }
        }
        int res[]=new int[queue.size()];
        int i=0;
        while(!queue.isEmpty()){
            res[i]=queue.poll();
            i++;
        }
        return res;
    }
}
