class Solution {
public:
    int calculate(string s) {
        stack<int> sign;
        sign.push(1);
        int ans = 0,num = 0,op = 1;
        for(char c:s){
            if(c==' ') continue;
            if('0'<=c && c<='9'){
                num = num*10 + (c-'0');
                continue;
            }
            ans += op*num;
            num = 0;
            if(c=='+'){
                op = sign.top();
            }else if(c=='-'){
                op = -sign.top();
            }else if(c=='('){
                sign.push(op);
            }else if(c==')'){
                sign.pop();
            }
        }
        ans += op*num;
        return ans;
    }
};

