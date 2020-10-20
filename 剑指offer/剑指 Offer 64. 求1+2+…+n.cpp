// 以逻辑运算符 && 为例，对于 A && B 这个表达式，如果 A 表达式返回 \textit{False}
// False ，那么 A && B 已经确定为 \textit{False}False ，此时不会去执行表达式 B。同理，
// 对于逻辑运算符 ||， 对于 A || B 这个表达式，如果 A 表达式返回 \textit{True}True ，那
// 么 A || B 已经确定为 \textit{True}True ，此时不会去执行表达式 B

class Solution {
public:
    int sumNums(int n) {
        n&& (n+=sumNums(n-1));
        return n;
    }
};



class Solution {
public:
    int sumNums(int n) {
        bool a[n][n+1];
        return (sizeof(a))>>1;

    }
};

