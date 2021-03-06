note1: K！尾部0的数量 和 K 是正相关的
note2: 结果只可能是 0 或者 5
note3: 注意K==0 这个边界条件， 如果不做处理，那么即使测试能通过， 在逻辑上也存在问题
note4: int 数据取值范围

class Solution {
public:
    int preimageSizeFZF(int K) {
        if(K == 0) return 5; // 如果不加入 这个case, 那么边界 == 0 输出正确结果完全是巧合 

        long long left = (long long)K;
        long long right = 5 * (long long)K + 1;

        while(left < right){
            long long mid = left + (right - left) / 2;
            int rstK = help(mid);
            if(rstK == K) return 5;
            if(rstK < K) {left = mid + 1;}  // 千万不能写成 left++, 否则时间复杂度就上升很多
            else{
                right = mid;
            }
        }

        return 0;
    }
    // 用以计算 K! 尾部 0 的个数
    int help(long long k){
        long long ans = 0;

        if(k < 5) return ans;
        
        while(k >= 5){
            ans += (k / 5);
            k /= 5;
        }
        return ans;
    }
};

