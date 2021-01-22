#include <bits/stdc++.h>

using namespace std;
int n;
bool check[7777][7777];
void f(int y,int x,int s){
    if(s == 3){
        check[y][x] = check[y+1][x+1] = check[y+1][x-1] = 1;
        x-=2;
        for(int i=0; i<5; i++) check[y+2][x+i] = 1;
    }
    if(s>3){
        int p = s/2;
        f(y+p,x-p,p);f(y+p,x+p,p);f(y,x,p);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    f(1,n,n);
    for(int i=1; i<=n; i++,cout<<"\n") for(int j=1; j<=n*2; j++) cout<<(check[i][j] ? "*" : " ");
}