#include <iostream>
#include <vector>

using namespace std;
int n,m;
bool check[10];
int a[10];
void dfs(int go,int s){
    if(go==m){
        for(int i=0; i<m; i++){
            cout<<a[i]<<' ';
        }
        cout<<"\n";
    }
    for(int i=s; i<=n; i++){
        if(check[i]==false){
            check[i]=true;
            a[go]=i;
            dfs(go+1,i+1);
            check[i]=false;
        }
    }
}
int main(){
    cin>>n>>m;
    dfs(0,1);
    return 0;
}
