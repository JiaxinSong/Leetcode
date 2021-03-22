//只能删除1个消耗b 增加1个消耗b 复制一倍消耗a
//问最短时间



#include<bits/stdc++.h>

using namespace std;
unsigned long long n, a, b;

long long dfs(unsigned long long n){
    if(n==0) return 0;
    if(n==1) return  b;

    unsigned long long res =  min( min(dfs(n/2) + a + b*(n%2), b*n), dfs(n/2) + b*(n-n/2));
    return min(res, dfs((n+1)/2) + a + b*(n%2));
}

int main(){

//    freopen("in.dat", "r", stdin);
    cin>>n>>b>>a;
    cout<<dfs(n)<<endl;
    return 0;
}
