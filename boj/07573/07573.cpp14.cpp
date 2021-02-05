#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n,m,k,ans,v;
pair<short,short> maps[101];
int go(int y,int x,int k){
	int dy = y + k;
	int uy = y;
	int lx = x;
	int rx = x + v-k;
	int ret = 0;
	for(int z = 1; z<=m; z++) if(uy <= maps[z].first && maps[z].first <= dy && lx <= maps[z].second && maps[z].second <= rx) ret++;
	//if(i == 1 && j == 2) cout<<i<<' '<<j<<' '<<k<<' '<<ret<<':'<<uy<<' '<<dy<<' '<<lx<<' '<<rx<<'\n';
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>v>>m;v>>=1;
	for(int i=1; i<=m; i++) cin>>maps[i].first>>maps[i].second;
	for(int i=1; i<=m; i++){
		for(int j=i; j<=m; j++){
			for(int k=1; k<v; k++){
				int y = min(maps[i].first,maps[j].first),x = min(maps[i].second,maps[j].second);
				ans = max(ans,go(y,x,k));
			}
		}
	}
	cout<<ans<<'\n';
}