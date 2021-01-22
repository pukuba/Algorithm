#include <bits/stdc++.h>

using namespace std;
int t,n,track[1111111],check[1111111],x[3]={3,5,8};
void bfs(int s){
    queue<pair<int,int> > q;
    check[s] = true;
    track[s] = 0;
    q.push({s,0});
    while(q.size()){
        auto[here,cnt] = q.front();
        if(here == 0) break;
        q.pop();
        for(int i=0; i<3; i++){
            int next = here - x[i];
            if(next < 0) continue;
            if(check[next]) continue;
            check[next] = true;
            track[next] = cnt+1;
            q.push({next,cnt+1});
        }
    }
}
void bfs1(int c){
    queue<pair<int,int> > q;
    q.push({0,c});
    while(q.size()){
        auto[here,cnt] = q.front();
        q.pop();
        if(here == n) break;
        for(int i=0; i<3; i++){
            int next = here + x[i];
            if(track[next] == cnt-1){
                cout<<x[i];
                q.push({next,cnt-1});
                break;
            }
        }
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        memset(track,-1,sizeof(track));
        memset(check,false,sizeof(check));
        cin>>n;
        bfs(n);
        if(track[0] != -1) bfs1(track[0]);
        if(track[0] == -1) cout<<-1<<'\n';
    }
}