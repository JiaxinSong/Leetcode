
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left =0,right=nums.size()-1;
        while(left<right){
            if((nums[left]&1)!=0){
                left++;
                continue;
            }
            if((nums[right]&1)!=1){
                right--;
                continue;
            }
            swap(nums[left++],nums[right--]);
          }
          return nums;
    }
};


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
