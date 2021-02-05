#include <iostream>

using namespace std;

int a[10];
int n,m;
void dfs(int go){
    if(go==m){
        for(int i=0; i<m; i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1; i<=n; i++){
        a[go]=i;
        dfs(go+1);
    }
}
int main(){
    cin>>n>>m;
    dfs(0);
    return 0;
}
