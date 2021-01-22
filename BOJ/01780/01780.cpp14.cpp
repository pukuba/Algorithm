#include <bits/stdc++.h>

using namespace std;
int n,a[2222][2222],ans[3];
void f(int y,int x,int s){
    bool can = true;
    int what = a[y][x];
    for(int i=y; i<y+s; i++) for(int j=x; j<x+s; j++) if(what-a[i][j]) can = false;
    if(!can){
        f(y,x,s/3); f(y,x+s/3,s/3); f(y,x+(s/3)*2,s/3);
        f(y+s/3,x,s/3), f(y+s/3,x+s/3,s/3); f(y+s/3,x+(s/3)*2,s/3);
        f(y+(s/3)*2,x,s/3); f(y+(s/3)*2,x+s/3,s/3);f(y+(s/3)*2,x+(s/3)*2,s/3);
    }
    else ans[what+1]++;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
    f(1,1,n);
    for(int i=0; i<=2; i++) cout<<ans[i]<<'\n';
}