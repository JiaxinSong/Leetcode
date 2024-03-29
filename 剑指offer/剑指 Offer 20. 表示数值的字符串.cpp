class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        while(s.length() > 0 && s[0] == ' ') s.erase(0, 1);
        while(s.length() > 0 && s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);
        if(s.length() == 0) return false;
        bool isDot = false, isE = false, isNumber = false;
        for(int i=0; i<s.length(); ++i)
        {          
            if(s[i] >= '0' && s[i] <= '9') 
                isNumber = true;
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(isE || !isNumber || i == s.length() - 1) return false;
                s[i] = 'e'; // 将'E'变成'e'
                isE = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if((i > 0 && s[i - 1] != 'e') || (i == s.length() - 1)) return false;
            }
            else if(s[i] == '.')
            {
                if(isDot || isE || (i == s.length() - 1 && !isNumber)) return false;
                isDot = true;
            }
            else return false;
        }
        return true;
    }
};

