#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
vector<pi> v[101];
int n,m,r,arr[111],dist[111],inf=1e9;
vector<int> ans;
void clear(){for(int i=1; i<=n; i++) dist[i]=inf;}
int check(int ret){
    for(int i=1; i<=n; i++) if(dist[i] <= m) ret+= arr[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=r; i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        v[from].push_back({to,weight});
        v[to].push_back({from,weight});
    }
    for(int i=1; i<=n; i++){
        clear();
        priority_queue<pi,vector<pi>,greater<>> pq;
        pq.push({0,i});
        dist[i] = 0;
        while(!pq.empty()){
            int here = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(dist[here] != weight) continue;
            for(pi i : v[here]){
                int next = i.first;
                int cost = i.second;
                if(dist[next] > dist[here] + cost){
                    dist[next] = dist[here] + cost;
                    pq.push({dist[next], next});
                }
            }
        }
        ans.push_back(check(0));
    }
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1];
}
