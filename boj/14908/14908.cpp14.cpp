#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct point{double t,s;int idx;};
ll d[1010],n;
point p[1010];
bool cmp(point a,point b){
	if(a.t / a.s == b.t / b.s) return a.idx < b.idx;
	return a.t / a.s < b.t / b.s;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>p[i].t>>p[i].s;
		p[i].idx = i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1; i<=n; i++) cout<<p[i].idx<<'\n';
}
