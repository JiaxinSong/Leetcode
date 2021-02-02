class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        int count = 0;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        for (int i = left; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++ count;
            }
        }

        return count;
    }
};
