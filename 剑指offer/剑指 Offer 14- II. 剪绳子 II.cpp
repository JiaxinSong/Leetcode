//1e7+9是double要转化成long
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        long res=1;
        while(n>4){
            res*=3;
            res%=(long)(1e9+7);
            n-=3;

        }
        return (int)(res*n%(long)(1e9+7));
    }
};
