#include <bits/stdc++.h>

using namespace std;
int d[5050][5050],n,a[5050],b[5050];
int f(int y,int x){
    if(y >= n || x >= n) return 0;
    if(d[y][x] != -1) return d[y][x];
    if(a[y] == b[x]) return d[y][x] = f(y+1,x+1) + 1;
    return d[y][x] = max(f(y+1,x),f(y,x+1));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(d,-1,sizeof(d));
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[n-i-1] = a[i];
    }
    cout<<n - f(0,0);
}
