// to_string   s.substr(起点，长度)  stoi
// 10~25  d[i]+=d[i-2] 
class Solution {
public:
    int translateNum(int num) {
        string s=to_string(num);
        const int n=s.size();
        int d[10]={0};
        d[0]=1;
        for(int i=1;i<n;++i){
            d[i]=d[i-1];
            string sub=s.substr(i-1,2);
            if(sub[0]!='0'&& stoi(sub)<=25)
                if(i-2>=0) d[i]+=d[i-2];
                else d[i]+=1;
        }
        return d[n-1];
    }
};
