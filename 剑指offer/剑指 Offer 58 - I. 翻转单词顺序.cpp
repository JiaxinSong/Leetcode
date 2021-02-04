class Solution {
public:
    string reverseWords(string s) {
        int left=s.size()-1;
        int right=s.size()-1;

        string ret="";
        while(left>=0){
            if(s[left]==' '){
                left--;
                right--;
                continue;
            }
            while(left>=0&& s[left]!=' '){
                left--;
            }
            if(left<right||left<0){
                ret.append(s.substr(left+1,right-left));
                ret.append(" ");
                right=left;
            }

        }
        ret=ret.substr(0,ret.size()-1);
        return ret;
    }
};
