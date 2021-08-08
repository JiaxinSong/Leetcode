class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> map=new HashMap<>();
        int res=0,pre=0;
        map.put(0,1);
        for(int num:nums){
            pre+=num;
            if(map.containsKey(pre-k)) res+=map.get(pre-k);
            map.put(pre,map.getOrDefault(pre,0)+1);
        }
        return res;
    }
}
