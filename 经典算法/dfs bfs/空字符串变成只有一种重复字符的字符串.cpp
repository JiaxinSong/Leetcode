//只能删除1个消耗b 增加1个消耗b 复制一倍消耗a
//问最短时间



#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1, 0);
    for(int i=0; i<n; i++){
        cin>>a[i+1];
        a[i+1] += a[i];
    }
    deque<int> que;
    int ans = 0;
    for(int i=0; i<=n; i++){
        while(!que.empty() && que.front()+m<i ){
            que.pop_front();
        }
        if(!que.empty())
            ans = max(ans, a[i] - a[que.front()]);
        while(!que.empty() && a[que.back()] >= a[i]){
            que.pop_back();

        }
        que.push_back(i);
    }
    cout<<ans<<endl;
    return 0;
}
