#include <bits/stdc++.h>

using namespace std;
vector<tuple<int,int,int> > adj;
int n,parent[333],ans,k;
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a,int b){
    parent[find(a)] = find(b);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1,x; i<=n; i++){
        parent[i] = i;
        cin>>x;
        adj.push_back({x,0,i});
    }
    for(int i=1; i<=n; i++){
        for(int j=1,x; j<=n; j++){
            cin>>x;
            if(i == j) continue;
            adj.push_back({x,i,j});
        }
    }
    sort(adj.begin(),adj.end());
    for(auto [a,b,c] : adj){
        if(k == n) break;
        if(find(b) == find(c)) continue;
        k++;
        ans += a;
        merge(b,c);
    }
    cout<<ans<<'\n';
}