#include <bits/stdc++.h>

using namespace std;
int n,dp[1010101][2];
bool check[1010101];
vector<int> adj[1010101];
void dfs(int here){
    check[here] = 1;
    dp[here][1] = 1;
    for(int next : adj[here]){
        if(check[next]) continue;
        dfs(next);
        dp[here][1] += min(dp[next][0],dp[next][1]);
        dp[here][0] += dp[next][1];
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout<<min(dp[1][0],dp[1][1]);
}