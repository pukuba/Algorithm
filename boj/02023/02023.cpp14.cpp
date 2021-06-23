#include <bits/stdc++.h>

using namespace std;
int N;
bool check(int x){
    for(int i=2; i*i<=x; i++){
        if(x%i == 0) return false;
    }
    return true;
}
void dfs(int here,int sz){
    if(!check(here)) return;
    if(sz == N){
        cout<<here<<'\n';
        return;
    }
    for(int i=1; i<=9; i++){
        dfs(here*10+i,sz+1);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    dfs(2,1);dfs(3,1);dfs(5,1);dfs(7,1);
}