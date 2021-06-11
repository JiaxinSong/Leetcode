class Solution {
    public int maxProfit(int[] prices) {
        int tmp=Integer.MAX_VALUE, res=0;
        for(int price:prices){
            res=Math.max(res,price-tmp);
            tmp=Math.min(tmp,price);
        }
        return res;
    }
}
