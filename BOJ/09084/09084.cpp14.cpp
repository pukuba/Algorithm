#include <bits/stdc++.h>

using namespace std;
main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> v;
		v.clear();
		int d[100001],x;
		memset(d,false,sizeof(d));
		d[0]=1;
		cin>>x;
		for(int i=0; i<x; i++){
			int k;
			cin>>k;
			v.push_back(k);
			for(int j=1; j<=100000; j++){
				if(j-v[i]>=0) d[j]+=d[j-v[i]];
			}
		}
		cin>>x;
		cout<<d[x]<<'\n';
	}
}