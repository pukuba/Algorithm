#include <bits/stdc++.h>

using namespace std;
int a[100001],cnt,t;
bool visited[100001],finished[100001];
void dfs(int here){
    visited[here] = 1;
    int next = a[here];
    if(visited[next]){
        if(!finished[next]){
            for(int i = next; i != here; i = a[i]){
                cnt++;
            }
            cnt++;
        }
    }else dfs(next);
    finished[here] = 1;
    return ;
}

int main(){
    cin>>t;
    while(t--){
        cnt=0;
        memset(a,false,sizeof(a));
        memset(visited,false,sizeof(visited));
        memset(finished,false,sizeof(finished));
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]) dfs(i);
        }
        cout<<n-cnt<<'\n';
    }
}
