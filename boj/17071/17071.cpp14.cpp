#include <bits/stdc++.h>

using namespace std;
int subin[2][500001],baby[500001],n,m,dx[3]={-1,1,2};
vector<int> ans;
bool in(int x){
    return (1<=x && x<=500000);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> >  q;
    cin>>n>>m;
    if(n==m){
        cout<<0<<'\n';
        return 0;
    }
    q.push({m,0});
    while(!q.empty()){
        auto [x,cnt] = q.front();
        baby[x]=cnt;
        int next_x=x+cnt+1;
        q.pop();
        if(!in(next_x)) continue;
        q.push({next_x,cnt+1});
    }
    q.push({n,0});
    while(!q.empty()){
        auto [x,cnt] = q.front();
        if(cnt==baby[x]){
            if(cnt){
                ans.push_back(cnt);
            }
        }
        if(subin[cnt%2][x]==baby[x] && !baby[x]) ans.push_back(baby[x]);
        else if( baby[x]>cnt && !((baby[x]-cnt)%2)) ans.push_back(((baby[x]-cnt)+cnt));
        q.pop();
        for(int i=0; i<3; i++){
            int next_x=x;
            if(dx[i]==2) next_x*=2;
            else next_x+=dx[i];
            if(!in(next_x)) continue;
            int next_cnt=cnt+1;
            int status=next_cnt%2; //0 짝 1 홀
            if(!subin[status][next_x]){
                subin[status][next_x]=next_cnt;
                q.push({next_x,next_cnt});
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        if(ans[i]){
            cout<<ans[i]<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
}
