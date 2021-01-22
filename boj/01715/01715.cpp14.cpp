#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
priority_queue<ull,vector<ull>,greater<>> pq;
ull n,x,ans,base;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    while(n--){
        cin>>x;
        pq.push(x);
    }
    while(pq.size()){
        base = pq.top();
        pq.pop();
        if(!pq.size()) break;
        base += pq.top();
        pq.pop();
        ans += base;
        pq.push(base);
    }
    cout<<ans<<'\n';
}
