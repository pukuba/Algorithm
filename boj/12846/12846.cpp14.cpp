#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,arr[111111];
int f(int s,int e){
	if(s+1 == e) return arr[s];
	if(s == e) return 0;
	int mid = s+e>>1;
	int _min=arr[mid],r=mid,l=mid;
	ll ret = max(f(s,mid),f(mid,e)),w=1;
	while(r-l+1 < e - s){
		int left_go = -1,right_go = -1;
		if(s<l) left_go = min(arr[l-1],_min);
		if(r<e-1) right_go = min(_min,arr[r+1]);
		if(left_go >= right_go){
			l--;
			_min = left_go;
		} 
		else{
			r++;
			_min = right_go;
		}
		ret = max(ret,++w*_min);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	cout<<f(1,n+1);
	
}