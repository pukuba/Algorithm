#include <bits/stdc++.h>

using namespace std;
int t,n,m,_end;
vector<int> adj[1004];
int _time[1004],in[1004],ret[1004];
int main(){
    cin>>t;
    while(t--){
        fill(_time, _time + 1004, 0);
        fill(in,in + 1004, 0);
        fill(ret,ret + 1004, 0);
        for(int i=0; i<1004; i++) adj[i].clear();
        cin>>n>>m;
        for(int i=1; i<=n; i++) cin>>_time[i];
        for(int i=1; i<=m; i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            in[y]++;
        }
        cin>>_end;
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int here = q.front();
            q.pop();
            for(int there : adj[here]){
                if(--in[there] == 0)q.push(there);
                ret[there] = max(ret[there],ret[here]+_time[here]);
            }
        }
        ret[_end]=ret[_end]+_time[_end];
        cout<<ret[_end]<<'\n';
        }
}
