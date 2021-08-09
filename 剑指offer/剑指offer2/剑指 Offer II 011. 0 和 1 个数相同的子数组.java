class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer,Integer> map=new HashMap<>();
        int sum=0;
        int len=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1) sum+=1;
            else sum-=1;
            if(i>0&&sum==0) len=i+1;
            if(map.containsKey(sum)){
                len = Math.max(len, i - map.get(sum));
            }
            else { //只记录第一次出现的sum的位置
                map.put(sum, i);
            }
        }
        return len;

    }
}
