#include <bits/stdc++.h>

using namespace std;
int n,a[2222][2222];
void f(int y,int x,int s){
    if(s==3){
        for(int i=y; i<y+3; i++) for(int j=x; j<x+3; j++){
            if(i==y+1 && j==x+1) continue;
            a[i][j] = 1;
        }
        return;
    }
    int p = s/3;
    f(y,x,s/3);f(y,x+p,p);f(y,x+p+p,p);
    f(y+p,x,p);f(y+p,x+p+p,p);
    f(y+p+p,x,p);f(y+p+p,x+p,p);f(y+p+p,x+p+p,p);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    f(1,1,n);
    for(int i=1; i<=n; i++,cout<<'\n') for(int j=1; j<=n; j++) cout<<(a[i][j] ? "*" : " ");
}
