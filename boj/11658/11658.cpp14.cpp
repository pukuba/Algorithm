#include <bits/stdc++.h>

using namespace std;
long long tree[1025][1025],a[1025][1025],n,m;
void update(int y,int x,int idx){
    while(y<=n ){
        int save=x;
        while(x<=n){
            tree[y][x]+=idx;
            x+=(x& -x);
        }
        x=save;
        y+=(y& -y);
    }
}
long long sum(int y,int x){
    long long ans=0;
    while(y){
        int save=x;
        while(x){
            ans+=tree[y][x];
            x-=(x&-x);
        }
        y-=(y& -y);
        x=save;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>a[i][j];
        update(i,j,a[i][j]);
    }
    while(m--){
        int x;
        cin>>x;
        if(x){
            int sy,sx,ey,ex;
            cin>>sy >> sx >> ey >> ex;
            cout<<sum(ey,ex)-sum(sy-1,ex)-sum(ey,sx-1)+sum(sy-1,sx-1)<<'\n';
        }
        else{
            int _a,b,c;
            cin>>_a>>b>>c;
            update(_a,b,c-a[_a][b]);
            a[_a][b] = c;
        }
    }
}
