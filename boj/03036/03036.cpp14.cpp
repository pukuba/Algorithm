#include <bits/stdc++.h>

using namespace std;
int n,a[111];
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=2; i<=n; i++){
		int div = gcd(a[1],a[i]);
		cout<<a[1]/div<<'/'<<a[i]/div<<'\n';
	}
}