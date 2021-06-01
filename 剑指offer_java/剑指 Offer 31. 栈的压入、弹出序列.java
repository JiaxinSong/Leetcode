class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Deque<Integer> stack = new LinkedList<>();
        int i = 0;
        for(int num : pushed) {
            stack.push(num); 
            while(!stack.isEmpty() && stack.peek() == popped[i]) { 
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }
}
