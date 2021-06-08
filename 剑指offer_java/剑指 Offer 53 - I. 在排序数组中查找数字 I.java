class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return 0;
        int x1=helper(nums, target+1);
        int x2=helper(nums, target);
        if(nums[x1]==target) return x1-x2+1;
        if(nums[x2]!=target) return 0; 
        return x1-x2;
    }
    int helper(int[] nums, int tar) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= tar) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
}
