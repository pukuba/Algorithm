#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,d[99]={1,1,1};
// 1
// 10
// 101 100
// 1001 1000 1010
// 5
// 8
// 13
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=3; i<=90; i++) d[i] = d[i-1] + d[i-2];
	cin>>n;
	cout<<d[n];
}