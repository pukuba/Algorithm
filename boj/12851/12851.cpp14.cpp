#include <bits/stdc++.h>

using namespace std;
int n,m,check[100004],ans[100001];
bool in(int a){
	return (0<=a && a<=100000);
}
main(){
	ios_base::sync_with_stdio(0);cout.tie(0);
	memset(check,-1,sizeof(check));
	cin>>n>>m;
	queue<pair<int,int> > q;
	if(n==m){
		cout<<0<<'\n'<<1<<'\n';
		return 0;
	}
	q.push({n,0});
	check[n]=0;
	while(!q.empty()){
		int cur_x=q.front().first;
		int cur_cnt=q.front().second;
		q.pop();
		if(in(cur_x*2)){
			if(check[cur_x*2]==-1){
				check[cur_x*2]=cur_cnt+1;
				ans[cur_x*2]++;
				q.push({cur_x*2,cur_cnt+1});
			}
			else if(check[cur_x*2]==cur_cnt+1) {
				ans[cur_x*2]++;
				q.push({cur_x*2,cur_cnt+1});
			}
		}
		if(in(cur_x+1)){
			if(check[cur_x+1]==-1){
				check[cur_x+1]=cur_cnt+1;
				ans[cur_x+1]++;
				q.push({cur_x+1,cur_cnt+1});
			}
			else if(check[cur_x+1]==cur_cnt+1){
				ans[cur_x+1]++;
				q.push({cur_x+1,cur_cnt+1});
		}
	}
		if(in(cur_x-1)){
			if(check[cur_x-1]==-1){
				check[cur_x-1]=cur_cnt+1;
				ans[cur_x-1]++;
				q.push({cur_x-1,cur_cnt+1});
			}
			else if(check[cur_x-1]==cur_cnt+1){
				ans[cur_x-1]++;
				q.push({cur_x-1,cur_cnt+1});
			}
		}
	}
	cout<<check[m]<<'\n'<<ans[m]<<'\n';
}