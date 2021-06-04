class Solution {
    public int countDigitOne(int n) {
        int high=n/10,digit=1,low=0,cur=n%10,res=0;
        while(high!=0||cur!=0){
            if(cur==0) res+= high*digit;
            else if(cur==1) res+=high*digit+low+1;
            else res+=high*digit+digit;
            digit*=10;
            low=n%digit;
            cur=high%10;
            high/=10;
        }
        return res;
    }
}
