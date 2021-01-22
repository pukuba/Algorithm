#include <bits/stdc++.h>

using namespace std;
int root[1000001],n,m,arr[1001];
bool check=true;
int find(int x){
    if(root[x]==x) return x;
    return root[x]=find(root[x]);
}
void _union(int x,int y){
    if(x>y) swap(x,y);
    x=find(x);
    y=find(y);
    root[y]=x;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=1000000; i++) root[i]=i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            if(x) _union(i,j);
        }
    }
    for(int i=1; i<=m; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=m-1; i++){
        if(find(arr[i])!=find(arr[i+1])) check=false;
    }
    if(check) cout<<"YES\n";
    else cout<<"NO\n";
}
