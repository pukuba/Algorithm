#include <bits/stdc++.h>

using namespace std;
int track[100001],_map[100001],n,m,dx[3]={2,-1,1},optimal;
stack<int> ans;
bool in(int a){return 0<=a && a<=100000;}
int main(){
    memset(_map,-1,sizeof(_map));
    memset(track,-1,sizeof(track));
    cin>>n>>m;
    queue<pair<int,int> > q;
    q.push({n,0});
    _map[n]=0;
    while(!q.empty()){
        auto [x,cnt] = q.front();
        track[x]=cnt;
        q.pop();
        if(x==m){
            cout<<cnt<<'\n';
            optimal=cnt;
            break;
        }
        for(int i=0; i<3; ++i){
            int next_x=x;
            if(i) next_x+=dx[i];
            else next_x*=2;
            if(!in(next_x)) continue;
            if(_map[next_x]==-1){
                _map[next_x]=cnt+1;
                q.push({next_x,cnt+1});
            }
        }
    }
    while(!q.empty())q.pop();
    q.push({m,optimal});
    while(!q.empty()){
        auto [x,cnt] = q.front();
        ans.push(x);
        q.pop();
        if(x==n) break;
        for(int i=0; i<3; i++){
            int next_x=x;
            if(dx[i]==2){
                if(next_x%2==0) next_x/=2;
                else continue;
            }
            else next_x+=dx[i];
            if(!in(next_x)) continue;
            if(track[next_x]==cnt-1){
                q.push({next_x,cnt-1});
                break;
            }
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
}
