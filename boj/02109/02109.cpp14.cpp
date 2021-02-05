#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<>> pq;
long long n,ans;
pair<int,int> p[10001];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i].second>>p[i].first;
    sort(p+1,p+n+1);
    for(int i=1; i<=n; i++){
        ans+=p[i].second;
        pq.push(p[i].second);
        if(pq.size() > p[i].first){
            ans-=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}
