//一串递减的数字，下一个数比这串数组的最大值还要大，那么该数是这串递减数字集合的最大值，那么一次遍历就能解决所有问题

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res(T.size(),0);
        for(int i=0;i<T.size();i++){
            while(!s.empty()&&T[i]>T[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
