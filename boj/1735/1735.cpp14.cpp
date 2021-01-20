#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b) : a;}
int a,b,n,m,angcd,bmgcd,anlcm,bmlcm,ans1,ans2;
int main(){
	cin>>a>>b>>n>>m;
	angcd = gcd(a,n);
	bmgcd = gcd(b,m);
	anlcm = a*n/angcd;
	bmlcm = b*m/bmgcd;
	ans1 += bmlcm/b * a;
	ans1 += bmlcm/m * n;
	ans2 = bmlcm;
	int div = gcd(ans1,ans2);
	cout<<ans1/div<<' '<<ans2/div<<'\n';
}