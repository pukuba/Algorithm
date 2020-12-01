#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i>=n; i--)
using namespace std;
int s,e,dx[3]={1,-1,2};
int check[300000];
bool in(int a){
	return (0<=a && a<=100001);
}
main(){
	memset(check,-1,sizeof(check));
	cin>>s>>e;
	vector<int> ans;
	queue<pair<int,int> > q;
	q.push({s,0});
	check[s]=0;
	while(!q.empty()){
		int cur_x=q.front().first;
		int cur_cnt=q.front().second;
		q.pop();
		if(cur_x==e){
			ans.push_back(cur_cnt);
		}
		rep(i,2,0){
			int next_x;
			int next_cnt;
			if(dx[i]==2){
				next_x=cur_x*2;
				next_cnt=cur_cnt;
			}
			else{
				next_x=cur_x+dx[i];
				next_cnt=cur_cnt+1;
			}
			if(in(next_x) && check[next_x]==-1 || check[next_x]>next_cnt){
				check[next_x]=next_cnt;
				q.push({next_x,next_cnt});
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0]<<'\n';
}