#include <bits/stdc++.h>

using namespace std;
int n,parent[100004],m,ans;
set<int> s;
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a,int b){
    parent[find(a)] = find(b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1,x; i<=m; i++){
        cin>>x;
        int check = find(x);
        if(!check) break;
        ans++;
        merge(check,check-1);
    }
    cout<<ans<<'\n';
}
