class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=1;
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(n==0){
                result=nums[i];
                n=1;

            }
            else if(result==nums[i]) n++;
            else n--;
        }
        return result;

    }
};
