//快慢指针 fast找奇数 slow是偶数

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int slow=0, fast=0;
        while(fast<nums.size()){
            if(nums[fast]&1){
            swap(nums[slow],nums[fast]);
            slow++;
            }
            fast ++;
        }
return nums;
    }

};
