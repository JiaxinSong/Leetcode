class Solution {
public:
    string reverseWords(string s)
{
    int left = (int)s.size() - 1;
    int right = (int)s.size() - 1;
    string ret = "";
    
    while(left >= 0)
    {
        while(left>=0&&s[left] == ' ')
        {
            left--;
            right--;
        }
        if(left<0) break;
        
        while(left >=0 && s[left] != ' ')
        {
            left--;
        }
        if(left < right || left < 0)
        {
            ret += s.substr(left + 1, right - left) + ' ';
            right = left;
            continue;
        }
    }
    ret = ret.substr(0,ret.size() - 1);//最后删除末尾空格
    return  ret;
}

};
