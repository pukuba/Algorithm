#include <bits/stdc++.h>

using namespace std;
int n,m,uf[1111111],check;
double ret;
vector<pair<int,int> > v;
struct point{int from,to;double weight; };
vector<point> ans;
int _find(int a){
    if(uf[a] < 0) return a;
    return _find(uf[a]);
}
bool cmp(point a,point b){return a.weight<b.weight;}
bool merge(int a,int b){
    a = _find(a);
    b = _find(b);
    if(a == b) return 0;
    else {
        uf[b] = a;
        return 1;
    }
}
void bfs(int here){
    for(int i=here+1; i<v.size(); i++){
        double dist = sqrt(pow(v[here].first - v[i].first,2) + pow(v[here].second - v[i].second,2));
        ans.push_back({here,i,dist});
    }
}
int main(){
    memset(uf,-1,sizeof(uf));
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        merge(a-1,b-1);
        check++;
    }
    for(int i=0; i<n; i++) bfs(i);
    sort(ans.begin(),ans.end(),cmp);
    int idx = 0;
    while(idx < ans.size()){
        if(check == n-1) break;
        if(merge(ans[idx].from,ans[idx].to)){
            check++;
            ret += ans[idx].weight;
        }
        idx++;
    }
    printf("%.2lf",ret);
}
