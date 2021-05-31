class Solution {
    public int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int a=1, b=1,sum=0;
        while(n>1){
            n--;
            sum=(a+b)%1000000007;
            a=b;
            b=sum;
        }
        return sum;
    }
}
