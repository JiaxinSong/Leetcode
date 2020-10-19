//动态规划

class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int n1=1,n2=1,N;
        while(n>=2){
            N=(n1+n2)%(int(1e9+7));
            n2=n1;
            n1=N;
            n--;
        }
        return N;

    }
};
