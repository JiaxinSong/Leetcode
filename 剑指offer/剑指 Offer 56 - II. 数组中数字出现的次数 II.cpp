根据题意我们可以找出这么一个规律：假设不存在这个 single number，那么 nums 中所有元素的二进制形式加起来之后，每一位必然都可以被 3 整除。因为每个数字都出现了三次，那么它们的二进制形式每一位也都出现了三次，那加起来之后每一位当然可以被 3 整除了。
现在加上这个 single number，我们可以进一步想到：同样把 nums 中所有元素的二进制形式加起来，这时候就不是每一位都能被 3 整除了，因为混入了一个只出现了一次的元素。所以我们只需要看加起来之后的和的哪一位不能被 3 整除，就说明这个 single number 的二进制形式在这一位是 1。然后把这些 single number 是 1 的位转换成十进制再加起来，就是 single number 的十进制形式了。
举个例子：假设 single number = 1，然后 nums 中所有元素的二进制形式加起来之后等于 3334（即 3333 + 1 = 3334）。那么我们就知道，4 这一位不能被 3 整除，说明 single number 在从右往左第一位是 1。然后因为剩下的全都能被 3 整除，所以 single number 在剩下的位上都是 0。由此可得 single number = 0001 = 1。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums) mp[n] ++;
        int ans;
        for(auto pr : mp){
            if(pr.second == 1){
                ans = pr.first;
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int cnt = 0;
            for(int n : nums){
                // n & 1 << i 的值大于0即为真
                if(n & (1 << i)) cnt++;
            }
            // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
            if(cnt % 3 == 1) ans += (1 << i);
        }
        return ans;
    }
};

