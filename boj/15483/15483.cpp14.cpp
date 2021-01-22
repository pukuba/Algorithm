#include <bits/stdc++.h>

using namespace std;
string a,b;
int d[1010][1010];
int f(int y,int x){
    if(y == a.size()) return b.size() - x;
    if(x == b.size()) return a.size() - y;
    if(d[y][x] != -1) return d[y][x];
    if(a[y] == b[x]) return d[y][x] = f(y+1,x+1);
    return d[y][x] = min({f(y,x+1),f(y+1,x),f(y+1,x+1)}) + 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(d,-1,sizeof d);
    cin>>a>>b;
    cout<<f(0,0);
}