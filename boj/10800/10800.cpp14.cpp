#include <bits/stdc++.h>

using namespace std;
int n,x,y,ans,color[222222],line[222222];
struct point{int c,s,idx;};
vector<point> v;
bool cmp(point &a,point &b){return a.s < b.s;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0,j=0; i<n; i++){
        for(;v[j].s < v[i].s; j++) ans+=v[j].s,color[v[j].c] += v[j].s;
        line[v[i].idx] = ans - color[v[i].c];
    }
    for(int i=1; i<=n; i++) cout<<line[i]<<'\n';
}