#include <bits/stdc++.h>

using namespace std;
struct point{long long from,to,weight;};
struct location{long long x,y,z,key;}l[100004];
vector<point> v;
long long n,uf[100004],ans,cnt=0;
bool cmp(point &a,point &b){return a.weight<b.weight;}
bool cmp1(location &a,location &b){return a.x<b.x;}
bool cmp2(location &a,location &b){return a.y<b.y;}
bool cmp3(location &a,location &b){return a.z<b.z;}
int find(long long a){
    if(uf[a]==a) return a;
    return uf[a]=find(uf[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    uf[a]=b;
}
void _push(int i){
    if(i==1){
        v.push_back({l[i].key,l[i+1].key,min({abs(l[i].x-l[i+1].x),abs(l[i].y-l[i+1].y),abs(l[i].z-l[i+1].z)})});
        return ;
    }
    if(i==n){
        v.push_back({l[i].key,l[i-1].key,min({abs(l[i].x-l[i-1].x),abs(l[i].y-l[i-1].y),abs(l[i].z-l[i-1].z)})});
        return ;
    }
    v.push_back({l[i].key,l[i+1].key,min({abs(l[i].x-l[i+1].x),abs(l[i].y-l[i+1].y),abs(l[i].z-l[i+1].z)})});
    v.push_back({l[i].key,l[i-1].key,min({abs(l[i].x-l[i-1].x),abs(l[i].y-l[i-1].y),abs(l[i].z-l[i-1].z)})});
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>l[i].x>>l[i].y>>l[i].z,l[i].key=uf[i]=i;
    sort(l+1,l+n+1,cmp1);
    for(int i=1; i<=n; i++) _push(i);
    sort(l+1,l+n+1,cmp2);
    for(int i=1; i<=n; i++) _push(i);
    sort(l+1,l+n+1,cmp3);
    for(int i=1; i<=n; i++) _push(i);
    n--;
    sort(v.begin(),v.end(),cmp);
    while(n){
        if(find(v[cnt].to)!=find(v[cnt].from)){
            merge(v[cnt].to,v[cnt].from);
            ans+=v[cnt].weight;
            n--;
        }
        cnt++;
    }
    cout<<ans<<'\n';
}
