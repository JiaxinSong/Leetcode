class Solution {
    public int majorityElement(int[] nums) {
        int x = 0, votes = 0;
        for(var num:nums){
            if(num==x) votes++;
            else {
                votes--;
                if(votes<=0) {
                    x=num;
                    votes=1;
                }
            }
        }
        return x;
    }
}
