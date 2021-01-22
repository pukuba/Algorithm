#include <bits/stdc++.h>

using namespace std;
//2 21 12 
int d[10]={0,0,2,6},n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=4; i<=9; i++) d[i] = d[i-1]*3;
	cout<<d[n];
}