//总结知道数组长度的随机查找 用vector 快很多


//方法一 慢很多：
//用map记录字符最后一个出现的位置
//如果找到重复 起点的位置就应该是现在的起点和重复位置+1的最大值
//更新字符最后一个出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 
 
        map<char, int> m;
        int ret = 0, l = 0, r = 0;
        for(;r<s.size();r++) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }
            m[s[r]] = r;
            ret = max(r - l+1, ret);
        }
        return ret;
    }
};


//方法二 很快：
//用vector记录字符最后一个出现的位置
//如果找到重复 起点的位置就应该是现在的起点和重复位置+1的最大值
//更新字符最后一个出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
 
        vector<int> m(128,-1);
        int res=0,left=0;
        for(int i=0; i<s.size();++i){
            if(m[s[i]]!=-1) {
            left = max(left,m[s[i]]+1); }
            m[s[i]]=i;
            res=max(res,i-left+1);
        }
        return res;
    }
};



