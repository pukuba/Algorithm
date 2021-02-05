#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
ll ans,n,m,a[101010],s,e,save;
ull ret;
priority_queue<ll,vector<ll>,less<ll>> pq;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    //freopen("/Users/erolf0123/Downloads/contest1_testdata/ljutnja/ljutnja.in.3","r",stdin);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>a[i];
        e = max(a[i],e);
    }
    while(s<=e){
        ll mid = s+e>>1,temp = n;
        bool go = 1;
        for(int i=1; i<=m; i++){
            if(a[i] > mid) temp -= a[i]-mid;
            if(temp < 0) go = 0;
        }
        if(go){
            e = mid - 1;
            ans = mid;
            save = temp;
        }
        else s = mid + 1;
    }
    for(int i=1; i<=m; i++) pq.push(min(a[i],ans));
    while(save-- && pq.size()){
        ll pqtop = pq.top()-1;
        pq.push(pqtop);
        pq.pop();
    }
    while(pq.size()){
        if(pq.top() < 0) break;
        ret += pq.top() * pq.top();
        pq.pop();
    }
    cout<<ret<<'\n';
    
}
