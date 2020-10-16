//注意变量名 ， string必须用引用

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        bt(s,0);
        return res;
    }
    void bt(string &s, int pos){
        if(pos== s.size()){
            res.push_back(s);
            return;
        }
        for(int i=pos;i<s.size();i++){
            if(prune(s,pos,i))  continue;   //当pos和i之间有等于i的值的时候剪枝
            swap(s[i],s[pos]);
            bt(s,pos+1);
            swap(s[i],s[pos]);
        }
    }

    //剪去重复的分支 
    bool prune(string &s, int start, int end){     
        for(int i=start;i<end;i++){
            if(s[i]==s[end]) return true;
        }
        return false;
    }
};

