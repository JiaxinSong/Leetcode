class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int N=0, minusone=1,minustwo=0;
        while(n>=2){
            N=(minusone+minustwo) %1000000007;
            minustwo=minusone;
            minusone=N;
            n--;
        }
        return N;
    } 
};
