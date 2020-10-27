class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1; // 当绳子的总长度<=3时，做特殊情况处理
        vector<int> res(n+1 , 0); // res[i]表示长度为i的绳子剪成若干段之后，乘积的最大值
        // 特殊处理：如果某个长度的绳子，剪了一下之后，其中一段的长度在[0,3]的区间内，就不要再剪这一段了
        // 因为剪了之后，乘积会变小，而res[i]是长度为i的绳子剪成若干段后能获得的最大乘积
        // 所以[res[0],res[3]]要单独处理（如下）
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;
        int maxProduct = 0;
        for(int i=4; i<=n; ++i)
        {
            maxProduct = 0;
            for(int j=1; j<=i/2; ++j)
            {
                // 循环体中写i/2是为了减少计算次数（因为比如1x3和3x1值是一样的，计算一次即可）
                int temp = res[j] * res[i-j];
                maxProduct = max(maxProduct, temp);
                res[i] = maxProduct; // res数组是做记忆化处理用的
            }  
        }
        return res[n];
    }
};  
