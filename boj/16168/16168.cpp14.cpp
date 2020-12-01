#include <bits/stdc++.h>

using namespace std;
vector<int> adj[3001];
bool check[3001]; //홀수개의 간선을 가진 정점이 0개 or 2개
int n,m,in[3001],chk;
void dfs(int node){
    for(int there : adj[node]){
        if(!check[there]){
            check[there]=true;
            dfs(there);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        in[y]++;
        in[x]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    check[1]=true;
    for(int i=1; i<=n; i++){
        if(in[i]%2==1) chk++;
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        if(!check[i]){
            cout<<"NO";
            return 0;
        }
    }
    if(chk==0 || chk==2) cout<<"YES";
    else cout<<"NO";
}
