#include <bits/stdc++.h>

using namespace std;
queue<pair<int,int> > q;
int n,a,b,dx[2]={-1,1};
vector<int> ans;
set<pair<int,int> > s;
bool in(int a){ return 1<= a&&a<=n;}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>a>>b;
    q.push({b,0});
    s.insert({b,0});
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        for(int i=0; i<2; i++){
            int next = 0;
            if(dx[i]==-1) next = cur_x - pow(2,cur_cnt);
            if(dx[i]==1) next = cur_x + pow(2,cur_cnt);
            if(!in(next)) continue;
            q.push({next,cur_cnt+1});
            s.insert({next,cur_cnt+1});
        }
    }
    q.push({a,0});
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        if(s.count({cur_x,cur_cnt})) ans.push_back(cur_cnt);
        for(int i=0; i<2; i++){
            int next = 0;
            if(dx[i] == 1) next = cur_x + pow(2,cur_cnt);
            if(dx[i] == -1) next = cur_x - pow(2,cur_cnt);
            if(!in(next)) continue;
            q.push({next,cur_cnt+1});
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()) cout<<ans[0];
    else cout<<-1<<'\n';
}
