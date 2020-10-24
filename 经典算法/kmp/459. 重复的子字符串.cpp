https://leetcode-cn.com/problems/repeated-substring-pattern/solution/tu-jie-yi-xia-shuang-bei-zi-fu-chuan-de-jie-fa-by-/

//s= aba  s+s=abaaba (s+s).find(s, 1)=s.size()
//只有在中间可以找到才可以由它的一个子串重复多次构成

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s, 1) != s.size();
    }
};




kmp:

// 12(字符串的长度) - 8(最长公共前后缀的长度) = 4， 4正好可以被 12(字符串的长度) 整除，所以说明有重复的子字符串（asdf）
//abcabcabc   abc是重复子串  


class Solution {
public:
    // KMP里标准构建next数组的过程
    void getNext (int* next, const string& s){
       next[0]=0;
       int slen=0;
       int elen=1;

       while(elen<s.size()){
           if(s[slen]==s[elen]) next[elen++]=++slen;
              
            else if(slen==0) next[elen++]=0;
            else slen=next[--slen];


           
       }
    }
    bool repeatedSubstringPattern (string s) {
        int a[s.size()];
        getNext(a,s);
        if(s.size()%(s.size()-a[s.size()-1])==0&&a[s.size()-1]!=0) return true;
        else return false;

        
    }
};

