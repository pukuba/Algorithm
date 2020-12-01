#include <bits/stdc++.h>

using namespace std;
int n,a[10001],_time[10001],d[10001];
vector<int> adj[10001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        _time[i]=x;
        int k;
        cin>>k;
        while(k--){
            int c;
            cin>>c;
            a[i]++;
            adj[c].push_back(i);
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!a[i]) q.push(i);
    }
    while(!q.empty()){
        int here=q.front();
        q.pop();
        for(int there : adj[here]){
            if(!--a[there]) q.push(there);
            d[there]=max(d[here]+_time[here],d[there]);
        }
    }
    int ans=1;
    for(int i=1; i<=n; i++){
        ans=max(ans,d[i]+_time[i]);
    }
    cout<<ans<<'\n';
}
