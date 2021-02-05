#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,k,a[1010101];
bool can[1010101];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>k;
	ll here = (((n-2)*(n-1)) + 1) / 2; 
	if(k > here){
		cout<<-1;
		return 0;
	}
	//17 - 6 
	//11 - 5
	//6 - 4
	//2 - 2
	for(int i=1; i<=n-2; i++){
		if(k - (n-1-i) >= 0){
			k -= (n-i-1);
			can[i] = 1;
		}
		if(!k) break;
	}
	for(int i=1; i<=n-2; i++) if(!can[i]) cout<<i<<' ';
	cout<<n-1<<' ';
	for(int i=1; i<=n-2; i++) if(can[i]) cout<<i<<' ';
	cout<<n;
}