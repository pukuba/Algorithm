#include <bits/stdc++.h>

using namespace std;
int n,d[1001][3],arr[1001][3],_min=1e9;
int dfs(int fir_color,int i,int color){
    if(n<i) return 0;
    if(i==n && fir_color == color ) return 1e9;
    if(d[i][color]!=-1) return d[i][color];
    int &ret = d[i][color];
    int ans=1e9,a,b;
    if(color==1) a=0,b=2;
    if(color==0) a=1,b=2;
    if(color==2) a=0,b=1;
    return ret=min({ans,dfs(fir_color,i+1,a)+arr[i+1][a],dfs(fir_color,i+1,b)+arr[i+1][b]});
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=0; j<3; j++) cin>>arr[i][j];
    for(int i=0; i<=3; i++,memset(d,-1,sizeof(d))) if(i) _min=min(_min,dfs(i-1,1,i-1)+arr[1][i-1]);
    cout<<_min;
}
