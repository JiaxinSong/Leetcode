class Solution {
public:

    bool check(string s){
        set<char> dic;
        for(auto c:s) dic.insert(c);
        for(auto c:s){
            if(c>='a' && c<='z' && dic.count(char(c-32))==0) return false;
            else if(c>='A' && c<='Z' && dic.count(char(c+32))==0) return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        string res="";
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(check(s.substr(i, j-i+1)) && res.size()<s.substr(i, j-i+1).size())
                    res = s.substr(i, j-i+1);
            }
        }
        return res;
    }
};
