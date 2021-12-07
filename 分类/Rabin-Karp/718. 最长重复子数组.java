class Solution {
    int base = 113;
    int mod = 1000000009;
    public int findLength(int[] A, int[] B) {
        //[left, right]是所有可能不存在“对应长度的公共子数组”的集合（0是一定存在的，所以left从1开始，
        // 而Math.min(A.length , B.length) + 1是一定不存在的，所以也需要包含在内）
        int left = 1;
        int right = Math.min(A.length , B.length) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(A, B, mid)) left = mid + 1;
            else right = mid;
        }
        return left - 1;
    }
    //检验是否存在长度为len的公共子数组
    private boolean check(int[] a, int[] b, int len) {
        //算出a[0, len - 1]的哈希值
        long hash_a = 0;
        for (int i = 0; i < len; i++) hash_a = (hash_a * base + a[i]) % mod;
        Set<Long> set_a = new HashSet<>();
        set_a.add(hash_a);
        //根据公式递推后面对应长度的哈希值，并存入哈希表
        long ref =  helper(len - 1) ;
        for (int i = 0; i < a.length - len; i++) {
            //+mod是为了保证hash_a大于0
            hash_a = ((hash_a - a[i] * ref % mod + mod) % mod * base + a[i + len]) % mod;
            set_a.add(hash_a);
        }
        //同样的方式处理B数组
        long hash_b = 0;
        for (int i = 0; i < len; i++) hash_b = (hash_b * base + b[i]) % mod;
        if (set_a.contains(hash_b)) return true;
        for (int i = 0; i < b.length - len; i++) {
            hash_b = ((hash_b - b[i] * ref % mod + mod) % mod * base + b[i + len]) % mod;
            if (set_a.contains(hash_b)) return true;
        }
        return false;
    }
    //求pow(base, len - 1),注意溢出问题
    private long helper(int i) {
        long res = 1;
        long ref = base;
        while (i != 0){
            //如果是奇数次幂，先抽一个底数出来，提前乘到结果中
            if(i % 2 != 0) {
                res = (res * ref) % mod;
            }
            //底数平方，幂减半
            ref = (ref * ref) % mod;
            i /= 2;
        }
        return res;
    }
}
