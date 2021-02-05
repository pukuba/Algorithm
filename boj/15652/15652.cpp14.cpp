#include <iostream>

using namespace std;
int a[10];
int n,m;
void dfs(int go,int start){
    if(m==go){
        for(int i=0; i<m; i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start; i<=n; i++){
        a[go]=i;
        dfs(go+1,i);
    }
}
int main(){
    cin>>n>>m;
    dfs(0,1);
    return 0;
}
