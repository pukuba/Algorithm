#include <bits/stdc++.h>

using namespace std;
int n,d1[44],d2[44];
int f(int k){
	if(k == 0) return 1;
	if(k == 1) return 0;
	if(d1[k] != -1) return d1[k];
	return d1[k] = f(k-2) + f(k-1); 
}

int ff(int k){
	if(k == 1) return 1;
	if(k == 0) return 0;
	if(d2[k] != -1) return d2[k];
	return d2[k] = ff(k-2) + ff(k-1); 
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	memset(d1,-1,sizeof(d1));memset(d2,-1,sizeof(d2));
	cin>>n;
	for(int x;n--;){
		cin>>x;
		cout<<f(x)<<' '<<ff(x)<<'\n';
	}
}