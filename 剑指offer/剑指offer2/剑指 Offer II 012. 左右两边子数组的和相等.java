class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, t = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        for(int i=0;i<nums.length;i++){
            t+=nums[i];
            if(sum-t == t-nums[i])return i;
        }
        return -1;
    }
}
