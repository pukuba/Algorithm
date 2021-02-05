#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int x;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>x;
	for(int i=1,y; i<=x*x; i++){
		cin>>y;
		pq.push(y);
		if(pq.size() > x) pq.pop();
	}
	cout<<pq.top();
}