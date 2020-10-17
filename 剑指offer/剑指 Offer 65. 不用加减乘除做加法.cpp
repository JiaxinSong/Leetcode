//a^=b 是不含进位的加法
//(unsigned int)(a & b)<<1是进位


// 加了unsigned之后，这个整形的各位其实是不变的，将其赋值给一个有符号数之后，符号位可以得到保留

// int a = -1;
// unsigned int b = a;
// int c = b;
// 这里c还是-1，b是4294967295
class Solution {
public:
    int add(int a, int b) {
        while(b){
            int carry =(unsigned int)(a & b)<<1;
            a^=b;
            b=carry;
        }
        return a;

    }
};
