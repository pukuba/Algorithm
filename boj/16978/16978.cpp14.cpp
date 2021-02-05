#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct p{int k,f,t,i;};
bool cmp(p a,p b){return a.k < b.k;}
int n,m,a[1000111],type,x,y,z,ut,cnt;
vector<pair<ll,ll> > q;
vector<p> q1;
ll tree[4444444],ans[100011];
void update(ll pos,ll value){for(;pos<=n;pos+=(pos&-pos))tree[pos]+=value;}
ll query(ll to,ll ret){for(;to;to-=(to&-to))ret+=tree[to];return ret;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(i,a[i]);
    }
    cin>>m;
    while(m--){
        cin>>type;
        if(type == 1){
            cin>>x>>y;
            q.push_back({x,y});
        }
        if(type == 2){
            cin>>x>>y>>z;
            q1.push_back({x,y,z,cnt++});
        }
    }
    sort(q1.begin(),q1.end(),cmp);
    for(int i=0; i<q1.size(); i++){
        while(q1[i].k != ut){
            update(q[ut].first,q[ut].second-a[q[ut].first]);
            a[q[ut].first] = q[ut].second;
            ut++;
        }
        ans[q1[i].i] = query(q1[i].t,0)-query(q1[i].f-1,0);
    }
    for(int i=0; i<cnt; i++) cout<<ans[i]<<'\n';
}