#include <bits/stdc++.h>

using namespace std;
int n,a[66][66];
void f(int y,int x,int s){
    int check = a[y][x];
    bool go = true;
    for(int i=y; i<y+s; i++) for(int j=x; j<x+s; j++) if(a[i][j] != check) go = false;
    if(!go){
        cout<<"(";
        f(y,x,s/2);f(y,x+s/2,s/2);
        f(y+s/2,x,s/2);f(y+s/2,x+s/2,s/2);
        cout<<")";
    }
    if(go) cout<<check;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%1d",&a[i][j]);
    f(1,1,n);
}
