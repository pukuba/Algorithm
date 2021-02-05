#include <bits/stdc++.h>

using namespace std;
int n;
long long d[31][31];
long long dfs(int a,int b){
    if(a==0 && b==0) return 1;
    if(d[a][b]!=-1) return d[a][b];
    long long &ret = d[a][b];
    ret = 0;
    if(a>0) ret += dfs(a-1,b+1);
    if(b>0) ret += dfs(a,b-1);
    return ret;
}
int main(){
    memset(d,-1,sizeof(d));
    while(true){
        int x;
        cin>>x;
        if(!x) break;
        cout<<dfs(x,0)<<'\n';
    }
}
