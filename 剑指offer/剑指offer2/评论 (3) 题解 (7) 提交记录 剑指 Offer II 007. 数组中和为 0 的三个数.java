class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len=nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for(int i=0;i<len; i++){
            if(i>0&& nums[i]==nums[i-1]) continue; 
            int L=i+1;
            int R=len-1;
            while(L<R){
                int sum=nums[i]+nums[L]+nums[R];
                if(sum==0){
                    ans.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while(L<R && nums[L]==nums[L+1]) L++;
                    while(L<R && nums[R]==nums[R-1]) R--;
                    L++;
                    R--;
                }
                else if(sum<0) L++;
                else if(sum>0) R--;
            }
        }
        return ans;
    }
}
