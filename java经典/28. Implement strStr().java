class Solution {
    vector<int> next;
    int n;
public:
    int strStr(string &str, string &pat) {
        n = pat.size();
        if (n == 0) return 0;
        getnext(pat);

        int i = 0, len = 0;
        while (i < str.size()) { //时间O(M)
            if (str[i] == pat[len]) { //字母相等，匹配成功，匹配长度+1
                ++i; ++len;
                if (len == n) return i - len;
            }
            else if (len == 0) ++i; //匹配失败，匹配长度为 0，无公共串
            else len = next[len - 1]; //匹配失败，看看公共串有没有前缀和后缀相等的部分，有的话，相等部分的后一个字母比较，没有的话证明当前字符串中没有与模式串前缀相等的部分
        }
        return -1;
    }

    void getnext(string& pat) { //时间O(N)
        next.resize(n);
        int len = 0, i = 1;
        while (i < n) {
            if (pat[i] == pat[len]) next[i++] = ++len;
            else if (len == 0) next[i++] = 0; //匹配失败，匹配长度为 0，无公共串
            else len = next[len - 1]; //匹配失败，看看公共串有没有前缀和后缀相等的部分，有的话，相等部分的后一个字母比较
        }
    }
};f
