#include <bits/stdc++.h>

using namespace std;

int uf[10001],n,m,my_money,fri_money[10001],x,y,ans;
bool check=true;
int find(int x){
    if(uf[x] < 0) return x;
    return uf[x]=find(uf[x]);
}
bool merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x == y) return true;
    else{
        if(fri_money[y]<fri_money[x]) uf[x] = y;
        else uf[y] = x;
        return false;
    }
}
int main(){
    fill(uf, uf + 10001, -1);
    cin>>n>>m>>my_money;
    for(int i=1; i<=n; i++) cin>>fri_money[i];
    for(int i=1; i<=m; i++){
        cin>>x>>y;
        if(find(x)!=find(y)) merge(x,y);
    }
    for(int i=1; i<=n; i++) if(uf[i]==-1) ans+=fri_money[i];
    if(check){
        if(my_money>=ans && ans!=0) cout<<ans<<'\n';
        else cout<<"Oh no"<<'\n';
    }
    else cout<<"Oh no";
}
