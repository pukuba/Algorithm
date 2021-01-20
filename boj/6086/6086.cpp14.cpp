#include <bits/stdc++.h>

using namespace std;
vector<int> v[1005];
bool check[1005][1005];
queue<int> q;
int f(char c){
    if('A'<=c && c<='Z') return c-'A';
    return c-'a'+26;
}
int n,ans,flow[1005][1005],capacity[1005][1005],start=f('A'),_end=f('Z');
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        char a,b;int c;
        cin>>a>>b>>c;
        capacity[f(a)][f(b)]+=c;
        capacity[f(b)][f(a)]+=c;
        v[f(a)].push_back(f(b));
        v[f(b)].push_back(f(a));
    }
    while(1){
        int prev[1005];
        memset(prev,-1,sizeof(prev));
        q.push(start);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0; i<v[cur].size(); i++){
                int next_cur=v[cur][i];
                if(prev[next_cur]==-1 && capacity[cur][next_cur]-flow[cur][next_cur] > 0){
                    prev[next_cur]=cur;
                    q.push(next_cur);
                    if(next_cur == _end) break;
                }
            }
        }
        if(prev[_end]==-1) break;
        int min_flow=1e9;
        for(int i=_end; i!=start; i=prev[i]) min_flow=min(min_flow,capacity[prev[i]][i]-flow[prev[i]][i]);
        ans+=min_flow;
        for(int i=_end; i!=start; i=prev[i]){
            flow[prev[i]][i]+=min_flow;
            flow[i][prev[i]]-=min_flow;
        }
    }
    cout<<ans;
}
