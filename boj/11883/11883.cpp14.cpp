#include <bits/stdc++.h>

using namespace std;
int t,d[1000044],x[3]={3,5,8},n;
queue<pair<int,int> > q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    memset(d,-1,sizeof(d));
    cin>>t;
    q.push({0,0});
    d[0] = 0;
    while(q.size()){
        auto[here,cnt] = q.front();
        q.pop();
        for(int i=0; i<3; i++){
            int next = here + x[i];
            if(next <= 1000000 && d[next] == -1){
                d[next] = cnt+1;
                q.push({next,cnt+1});
            }
        }
    }
    while(t--){
        cin>>n;
        if(d[n] == -1) cout<<-1<<'\n';
        else{
            q.push({n,d[n]});
            while(q.size()){
                auto[here,cnt] = q.front();
                q.pop();
                if(here == 0) break;
                for(int i=0; i<3; i++){
                    int next = here - x[i];
                    if(next < 0) continue;
                    if(d[next] == cnt-1){
                        q.push({next,cnt-1});
                        cout<<x[i];
                        break;
                    }
                }
            }
            while(q.size()) q.pop();
            cout<<'\n';
        }
    }
}