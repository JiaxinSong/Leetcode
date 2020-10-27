class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x =INT_MAX;
        int res=0;
        for(int i;i<prices.size();i++ ){
          //if(prices[i]<x) x=prices[i];
          x=min(x,prices[i]);
          res=  max(res,prices[i]-x);
        }
        return res;
    }
};
