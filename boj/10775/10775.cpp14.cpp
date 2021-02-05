#include <bits/stdc++.h>

using namespace std;
int n,parent[100004],m,ans,temp;
int find(int x){
    if(parent[x] == x) return x;
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
        if(!find(x)) break;
        ans++;
        merge(find(x),find(x)-1);
    }
    cout<<ans<<'\n';
}