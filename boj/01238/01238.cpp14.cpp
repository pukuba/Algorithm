#include <bits/stdc++.h>

using namespace std;
int n,m,k,dist1[10001],dist2[10001];
#define pi pair<int,int>
vector<pi> v[10001];
vector<pi> v2[10001];
bool check[20001];
const int INF=987654321;
priority_queue<pi,vector<pi>,greater<pi>> pq;
int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(pi(c,b));
        v2[b].push_back(pi(c,a));
    }
    fill(dist1, dist1 + 10001, INF);
    fill(dist2, dist2 + 10001, INF);
    dist1[k] = 0;
    pq.push(pi(0,k));
    while(!pq.empty()){
        int here = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist1[here] != dist) continue;
        for(pi i : v[here]){
            int next = i.second;
            int height = i.first;
            if(dist1[here]+height < dist1[next]){
                dist1[next]=dist1[here]+height;
                pq.push(pi(dist1[next],next));
            }
        }
    }
    dist2[k]=0;
    pq.push(pi(0,k));
    while(!pq.empty()){
        int here = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist2[here] != dist) continue;
        for(pi i : v2[here]){
            int next = i.second;
            int height = i.first;
            if(dist2[here]+height < dist2[next]){
                dist2[next]=dist2[here]+height;
                pq.push(pi(dist2[next],next));
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(dist1[i]+dist2[i],ans);
    cout<<ans<<'\n';
}
