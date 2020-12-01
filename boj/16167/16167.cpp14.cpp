#include <bits/stdc++.h>

using namespace std;
struct point{int x,weight,cnt;};
vector<pair<int,int> > v[111],ans;
pair<int,int> dist[111];
queue<point> q;
int n,r,inf=1e9;
int main(){
    for(int i=1; i<=100; i++) dist[i].first = dist[i].second = inf;
    cin>>n>>r;
    for(int i=1; i<=r; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(e > 10 ) v[a].push_back({b,(e-10)*d+c});
        else v[a].push_back({b,c});
    }
    q.push({1,0,1});
    dist[1] = {0,0};
    while(!q.empty()){
        auto [here,weight,cnt] = q.front();
        q.pop();
        if(here == n){
            ans.push_back({weight,cnt});
            continue;
        }
        for(pair<int,int> i : v[here]){
            int next_weight = i.second;
            int next = i.first;
            if(dist[next].first >= dist[here].first + next_weight){
                dist[next].first = dist[here].first + next_weight;
                dist[next].second = dist[here].second + 1;
                q.push({next,weight+next_weight,cnt+1});
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()) cout<<ans[0].first<<' '<<ans[0].second;
    else cout<<"It is not a great way.";
}
