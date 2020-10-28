class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> counter(100010, 0);
        for (int n : nums) {
            counter[n + 50000] ++;
        }
        vector<int> res;
        for (int i = 0; i < 100010; ++i) {
            if (counter[i] != 0) {
                res.insert(res.end(), counter[i], i - 50000);
            }
        }
        return res;
    }
};

