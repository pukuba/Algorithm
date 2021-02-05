#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,dist[555],cycle[555];
bool check[555];
vector<pair<int,int> > adj[555];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    for(int i=1,x,y,d; i<=m; i++){
        cin>>x>>y>>d;
        adj[x].push_back({y,d});
    }
    q.push(1);
    check[1] = true;
    dist[1] = 0;
    cycle[1]++;
    while(q.size()){
        int here = q.front();
        q.pop();
        check[here] = false;
        for(pair<int,int> i : adj[here]){
            if(dist[i.first] > dist[here] + i.second){
                dist[i.first] = dist[here] + i.second;
                if(cycle[i.first] == n){
                    cout<<-1<<'\n';
                    return 0;
                }
                if(!check[i.first]){
                    cycle[i.first]++;
                    check[i.first] = true;
                    q.push(i.first);
                }
            }
        }
    }
    for(int i=2; i<=n; i++) cout<<(dist[i]>1e9?-1:dist[i])<<'\n';
}