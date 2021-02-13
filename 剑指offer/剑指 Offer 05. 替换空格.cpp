class Solution {
public:
    string replaceSpace(string s) {
        string str="";
        if(s.empty()) return str;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                str+="%20";
            }else{
                str+=s[i];
            }
        }
        return str;
    }
};
