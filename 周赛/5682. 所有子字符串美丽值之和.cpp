class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            multiset<int> st;
            vector<int> cnt(26);
            for (int j = i; j < n; ++j) {
                int c = s[j] - 'a';
                if (st.find(cnt[c]) != st.end())
                    st.erase(st.find(cnt[c]));
                st.insert(++cnt[c]);
                ans += *st.rbegin() - *st.begin();
            }
        }
        return ans;
    }
};

