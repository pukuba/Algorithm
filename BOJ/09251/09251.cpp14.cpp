#include <bits/stdc++.h>

using namespace std;
string a,b;
int d[1010][1010];
int f(int x,int y){
    if(d[x][y] != -1) return d[x][y];
    if(x == a.size() || y == b.size()) return 0;
    if(a[x] == b[y]) return f(x+1,y+1) + 1;
    return d[x][y] = max(f(x+1,y),f(x,y+1));
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    memset(d,-1,sizeof d);
    cout<<f(0,0);
}