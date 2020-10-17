//由于有n个数在0~n-1范围内 每个数可以正好放在等于下标的位置上
//一旦发现当前下标的数和应该存在的位置的数相当就返回


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i){
                i++;
                continue;
            }
            if(nums[nums[i]]==nums[i]){
                return nums[i];
            }
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};
