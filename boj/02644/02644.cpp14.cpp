#include <bits/stdc++.h>

using namespace std;
int n,a,b,m;
vector<int> adj[131];
bool check[555];
queue<pair<int,int> > q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>a>>b>>m;
    for(int i=1,x,y; i<=m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push({a,0});
    while(q.size()){
        auto[x,y] = q.front();
        if(x == b){
            cout<<y;
            return 0;
        }
        q.pop();
        for(int i : adj[x]){
            if(!check[i]) check[i] = 1,q.push({i,y+1});
        }
    }
    cout<<-1<<'\n';
}