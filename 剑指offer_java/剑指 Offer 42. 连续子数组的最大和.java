class Solution {
    public int maxSubArray(int[] nums) {
        int tmp = nums[0];
        int res=tmp;
        for(int i=1;i< nums.length;i++){
            if(tmp>0) tmp+=nums[i];
            else tmp=nums[i];
            res=Math.max(res,tmp);
        }
        return res;
    }
}
