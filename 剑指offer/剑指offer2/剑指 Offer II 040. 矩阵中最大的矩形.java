class Solution {
    public int maximalRectangle(String[] matrix) {
        int res=0;
        if(matrix.length== 0|| matrix[0].length()==0) return 0;
        int[] x=new int[matrix[0].length()];
        for( int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length();j++){
                if(matrix[i].charAt(j)=='1') x[j]+=1;
                else x[j]=0;
            }
            res= Math.max(largestRectangleArea(x),res);
        }

        return res;
    }


    public int largestRectangleArea(int[] heights) {
        int res = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        int[] new_heights = new int[heights.length + 1];
        for (int i = 0; i < heights.length ; i++) {
            new_heights[i] = heights[i];
        }
        for (int i = 0; i < new_heights.length; i++) {
            while (!stack.isEmpty() && new_heights[stack.peek()] > new_heights[i]) {
                int cur = stack.pop();
                if(stack.isEmpty()) res=Math.max( res, i*new_heights[cur]);
                else res = Math.max(res, (i - stack.peek() - 1) * new_heights[cur]);
            }
            stack.push(i);
        }
        return res;
    }
}
