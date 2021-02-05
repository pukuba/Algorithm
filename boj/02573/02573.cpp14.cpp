#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
short _map[301][301],s_x,s_y,ans,n,m,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},cnt;
bool check[301][301],check1[301][301];
queue<pair<int,int> > q;
bool in(int a,int b){
	return (1<=a && a<=n && 1<=b && b<=m);
}
main(){
	cin>>n>>m;
	rep(i,1,n) rep(j,1,m){
		cin>>_map[i][j];
		if(ans<_map[i][j]){
			ans=_map[i][j];
			s_x=j,s_y=i;
		}
	}
	while(1){
		cnt++;
		memset(check,false,sizeof(check));
		memset(check1,false,sizeof(check1));
		q.push(pair<int,int>(1,1));
		q.push(pair<int,int>(n,m));
		check[n][m]=true;
		check[1][1]=true;
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			rep(i,0,3){
				if(in(p.first+dy[i],p.second+dx[i]) && !check[p.first+dy[i]][p.second+dx[i]]){
					if(_map[p.first+dy[i]][p.second+dx[i]]>=2 && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						_map[p.first+dy[i]][p.second+dx[i]]--;
						check[p.first][p.second]=1;	
					} 
					else if(_map[p.first+dy[i]][p.second+dx[i]]==1 && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						_map[p.first+dy[i]][p.second+dx[i]]--;
						check[p.first+dy[i]][p.second+dx[i]]=1;
						check[p.first][p.second]=1;
					}
					else if(!_map[p.first+dy[i]][p.second+dx[i]] && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						check[p.first+dy[i]][p.second+dx[i]]=1;
						q.push(pair<int,int>(p.first+dy[i],p.second+dx[i]));
					}
				}
			}
		}
		rep(i,1,n) rep(j,1,m){
			if(!_map[i][j] && !check[i][j]){
				q.push({pair<int,int>(i,j)});
				check[i][j]=true;
			}
		} 
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			rep(i,0,3){
				if(in(p.first+dy[i],p.second+dx[i]) && !check[p.first+dy[i]][p.second+dx[i]]){
					if(_map[p.first+dy[i]][p.second+dx[i]]>=2 && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						_map[p.first+dy[i]][p.second+dx[i]]--;
						check[p.first][p.second]=1;	
					} 
					else if(_map[p.first+dy[i]][p.second+dx[i]]==1 && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						_map[p.first+dy[i]][p.second+dx[i]]--;
						check[p.first+dy[i]][p.second+dx[i]]=1;
						check[p.first][p.second]=1;
					}
					else if(!_map[p.first+dy[i]][p.second+dx[i]] && !check[p.first+dy[i]][p.second+dx[i]] &&in(p.first+dy[i],p.second+dx[i])){
						check[p.first+dy[i]][p.second+dx[i]]=1;
						q.push(pair<int,int>(p.first+dy[i],p.second+dx[i]));
					}
				}
			}
		}
		bool check61=false;
		rep(i,1,n){
			rep(j,1,m){
				if(_map[i][j]>0){
					check61=true;
					q.push(pair<int,int> (i,j));
					check1[i][j]=true;
					break;
				}
			}
			if(check61) break;
		}
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			rep(i,0,3){
				if(in(p.first+dy[i],p.second+dx[i]) && _map[p.first+dy[i]][p.second+dx[i]]!=0 && !check1[p.first+dy[i]][p.second+dx[i]]){
					check1[p.first+dy[i]][p.second+dx[i]]=1;
					q.push(pair<int,int>(p.first+dy[i],p.second+dx[i]));
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(_map[i][j]>0 && !check1[i][j]){
					cout<<cnt<<'\n';
					return 0;
				}
			}
		}
		bool bk_check=false;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(_map[i][j]>0) bk_check=true;
			}
		}
		if(!bk_check) break;
	}
	cout<<"0";
}