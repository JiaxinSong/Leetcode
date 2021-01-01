class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right){
        int i= left, j= right;
        int pivot= nums[left+(right-left)/2];
        while(i<=j){        //确保数组被分成两部分
            while(nums[i]<pivot){   //确保数组被分成正确的两部分   例如0 1 0
                i++;
            }
            while(nums[j]>pivot){  
                j--;
            }
            if(i<=j){                //  确保数组被分成正确的两部分
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        if(j>left) quick_sort(nums,left,j);
        if(i<right) quick_sort(nums,i,right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};
