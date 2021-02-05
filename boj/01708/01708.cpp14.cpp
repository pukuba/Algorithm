#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
vector<pii> v;
ll n;
ll ccw(pii a,pii b,pii c) {
    ll temp = a.first*b.second+b.first*c.second+c.first*a.second;
    temp -= a.second*b.first+b.second*c.first+c.second*a.first;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }	
}
ll dist(pii a, pii b){
	return ((a.first-b.first) * (a.first-b.first)) + ((a.second-b.second) * (a.second-b.second));
}
bool cmp(pii a, pii b){
	if(ccw(v[0],a,b) == 0){
		return dist(v[0],a) < dist(v[0],b);
	}
	return ccw(v[0],a,b) < 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=1,x,y; i<=n; i++){
		cin>>x>>y;
		v.push_back({x,y});
	}
	swap(v[0],*max_element(v.begin(),v.end()));
	vector<pair<ll,ll>> hull;
	hull.push_back(v[0]); 
	sort(v.begin()+1,v.end(), [&](const pii &i, const pii &j) {
        if (ccw(v[0], i, j) == 0) {
            return dist(v[0], i) < dist(v[0], j);
        }
        return ccw(v[0], i, j) < 0;
    });
	for(ll i=1; i<v.size(); i++){
		while(hull.size() > 1 && ccw(hull[hull.size()-2],hull.back(),v[i]) >= 0){
			hull.pop_back();
		}
		hull.push_back(v[i]);
	}
	cout<<hull.size();
}