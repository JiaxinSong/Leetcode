class Solution {
public:
    char firstUniqChar(string s) {
        int a[26] = {0};
        if(s == "") return ' ';
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            a[b] += 1;
        }
        for(int i = 0; i < s.size(); i++)
        {
            int b = s[i] - 'a';
            if(a[b] == 1) return s[i];
        }
        return ' ';
    }
};
