#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k;
vector<pair<int,int> > v;
ll ans;
struct Point{
    ll maxTime, id, cacher_id;
    Point(){
        maxTime = 0;
        id = 0;
        cacher_id = 0;
    }
    Point(ll maxTime, ll id, ll cacher_id) : maxTime(maxTime), id(id), cacher_id(cacher_id){}
    bool operator < (const Point & _a) const{
        if(maxTime == _a.maxTime) return cacher_id > _a.cacher_id;
        return maxTime > _a.maxTime;
    }
};
bool cmp(Point a,Point b){
    if(a.maxTime == b.maxTime) return a.cacher_id > b.cacher_id;
    return a.maxTime < b.maxTime;
}
priority_queue<Point> pq;
vector<Point> pt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(i < k){
            pq.push({y, x, i + 1}); continue;
        }
        pq.push({pq.top().maxTime + y, x, pq.top().cacher_id});
        pt.push_back(pq.top());
        pq.pop();
    }
    while(pq.size()){
        pt.push_back(pq.top()); pq.pop();
    }
    sort(pt.begin(),pt.end(),cmp);
    for(int i=0; i<pt.size(); i++) ans+= 1LL * pt[i].id * (i+1);
    cout<<ans<<'\n';
}
