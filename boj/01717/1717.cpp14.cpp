#include <bits/stdc++.h>

using namespace std;
int root[1000001],n,m;
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
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(!a) _union(b,c);
        else{
            if(find(b)==find(c)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
