#include <bits/stdc++.h>

using namespace std;
int n,k,cycleSize,cnt,ret,cycle[1001],compSize[1001],_cycle,comp[1001],a[1001],finished[1001];
bool d[1001],check[1001],finised[1001];
int dfs(int curr,int cnt){
	check[curr]=cnt;
	comp[curr]=cnt;
	int _compSize=1;
	int next=a[curr];
	if(check[next]){
		if(!finished[next]){
			_cycle=1;
			for(int i=next; i!=curr; i=a[i]) _cycle++;
			cycle[cnt]=_cycle;
		}
	}
	else{
		_compSize+=dfs(next,cnt);
	}
	finished[curr]=1;
	return _compSize;
	
}
main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		if(!check[i]){
			int next=a[i];
			int _id=comp[next];
			if(_id){
				compSize[_id]++;
				comp[i]=_id;
			}
			else{
				cnt++;
				compSize[cnt]=dfs(i,cnt);
			}
		}
	}
	d[0]=1;
	for(int i=1; i<=cnt; i++){
		for(int j=k; j>=1; j--){
			for(int _size=cycle[i]; _size<=compSize[i]; _size++){
				if(j-_size >=0) d[j]|=d[j-_size];
			}
		}
	}
	for(int i=k; i>=0; i--){
		if(d[i]){
			ret=i;
			break;
		}
	}
	cout<<ret<<'\n';
}