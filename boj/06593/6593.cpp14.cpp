#include <bits/stdc++.h>

using namespace std;
int l,n,m,dx[6]={-1,0,1,0,0,0},dy[6]={0,-1,0,1,0,0},dz[6]={0,0,0,0,-1,1};
bool check[31][31][31];
char arr[31][31][31]; 
bool in(int c,int a,int b){
	return (1<=c && c<=l && 1<=a && a<=n && 1<=b && b<=m);
}
struct point{
	int z,y,x,cnt;
};
int main(){
	while(1){
		cin>>l>>n>>m;
		int ez,ex,ey;
		queue<point> q;
		if(l==0 && n==0 && m==0) return 0;
		memset(check,false,sizeof(check));
		fill(&arr[0][0][0],&arr[31][31][31],NULL);
		for(int i=1; i<=l; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=m; k++){
					cin>>arr[i][j][k];
					if(arr[i][j][k]=='S'){
						q.push({i,j,k,0});
						check[i][j][k]=true; 
					}
					if(arr[i][j][k]=='E'){
						ez=i;
						ex=k;
						ey=j;
					}
				}
			}
		}
		bool ans=false;
		while(!q.empty()){
			int cur_x=q.front().x;
			int cur_y=q.front().y;
			int cur_z=q.front().z;
			int cur_cnt=q.front().cnt;
			q.pop();
			if(cur_x==ex && cur_y==ey && cur_z==ez){
				cout<<"Escaped in "<<cur_cnt<<" minute(s).\n";
				ans=true;
				break;
			}
			for(int i=0; i<6; i++){
				int next_x=cur_x+dx[i];
				int next_y=cur_y+dy[i];
				int next_z=cur_z+dz[i];
				int next_cnt=cur_cnt+1;
				if(in(next_z,next_y,next_x) && check[next_z][next_y][next_x]==false && arr[next_z][next_y][next_x]!='#'){
					check[next_z][next_y][next_x]=true;
					q.push({next_z,next_y,next_x,next_cnt});
				}
			}
		}
		if(!ans){
			cout<<"Trapped!\n";
		}
	}
}