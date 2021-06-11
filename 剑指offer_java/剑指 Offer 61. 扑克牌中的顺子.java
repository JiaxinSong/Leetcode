class Solution {
    public boolean isStraight(int[] nums) {
        Set<Integer> repeat=new HashSet<>();
        int max=0,min=14;
        for(int num:nums){
            if(num==0) continue;
            max=Math.max(max,num);
            min=Math.min(min,num);
            if(repeat.contains(num)) return false;
            repeat.add(num);
        }
        return max-min<5;
    }
}

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count_0 = 0;
        int i;
        for (i = 0; i < nums.size(); i++) // 统计0的个数
        {
            if (nums[i] == 0)
                count_0++;
            else
                break;
        }
        while(i+1 < nums.size()) // 接着遍历0后面的数
        {
            if(nums[i+1] == nums[i]+1) // 如果是顺子就遍历下一张
                i++;
            else
            {
                if(--count_0 < 0) return false; // count当作万能牌，用一张少一张，当没有万能牌时就不是顺子。
                nums[i] += 1; // 用完一张的效果：将当前的数加一
            }
        }
        return true;
    }
};
