class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return helper(postorder,0,postorder.length-1);
    }
    boolean helper(int[] postorder, int start, int end){
        if(start>=end) return true;
        int rootVal=postorder[end];
        int a=start;
        while(a<end&& postorder[a]<rootVal) a++;
        int b=a;
        while(b<end&& postorder[b]>rootVal) b++;
        if(b!=end) return false;
        return helper(postorder,start,a-1)&&helper(postorder,a,end-1);
    }
}
