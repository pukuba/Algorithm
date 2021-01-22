#include <iostream>

using namespace std;
int n,m;
bool check[10];
int p[10];
void dfs(int go){
    if(go==m){
        for(int i=0; i<m; i++){
            cout<<p[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(check[i]==false){
            check[i]=true;
            p[go]=i;
            dfs(go+1);
            check[i]=false;
        }
    }
}
int main(){
    cin>>n>>m;
    dfs(0);
    return 0;
}
