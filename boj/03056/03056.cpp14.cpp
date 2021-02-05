#include <bits/stdc++.h>

using namespace std;
int n;
double d[1<<21],a[21][21];
vector<int> v;
double dfs(int check,int go){
    double &ret = d[check];
    if(check == (1<<n)-1) return 1;
    if(ret != 0.0) return ret;
    ret = 0;
    for(int i=1; i<=n; i++){
        if(check & (1<<(i-1))) continue;
        ret = max(ret,dfs(check | (1<<(i-1)),go+1)*a[go][i]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cout.precision(6); cout<<fixed;
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>a[i][j];
        a[i][j]/=100;
    }
    cout<<dfs(0,1)*100.0;
}
