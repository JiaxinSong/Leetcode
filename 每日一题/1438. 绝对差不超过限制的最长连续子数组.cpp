class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queMax, queMin;
        int n = nums.size();
        int left = 0, right = 0;
        int ret = 0;
        while (right < n) {
            while (!queMax.empty() && queMax.back() < nums[right]) {
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back() > nums[right]) {
                queMin.pop_back();
            }
            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit) {
                if (nums[left] == queMin.front()) {
                    queMin.pop_front();
                }
                if (nums[left] == queMax.front()) {
                    queMax.pop_front();
                }
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> cnt;
        int ans = 1, n = nums.size();
        for(int left = 0, right = 0; right < n; right++){
            cnt[nums[right]]++;
            while(cnt.rbegin()->first - cnt.begin()->first > limit) if(--cnt[nums[left++]] == 0) cnt.erase(nums[left-1]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
