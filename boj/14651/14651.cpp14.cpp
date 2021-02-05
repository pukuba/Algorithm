#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
long long d[33334],n;
main(){
	cin>>n;
	d[2]=2;
	for(int i=3; i<=n; i++) d[i]=(d[i-1]*3)%mod;
	cout<<d[n];
} 