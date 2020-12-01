#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n,ans,a[1111111],d[1111111],k,len;
/*
6
10 20 10 30 20 50
*/
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		auto it = lower_bound(d,d+len,a[i]);
		//cout<<*it<<' ';
		if(*it == 0){
			len++;
			k++;
		}
		*it = a[i];
	}
	cout<<k;
}