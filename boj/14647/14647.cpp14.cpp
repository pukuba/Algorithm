#include <bits/stdc++.h>

using namespace std;
int xcheck(vector<vector<int> > &vec,int a,int b,int ans);
int ycheck(vector<vector<int> > &vec,int a,int b,int ans);
int n,m;
int cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	vector<vector<int> > v(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int x;
			cin>>x;
			int cnt=0;
			while(x>=8){
				if(x%10==9) cnt++;
				x/=10;
			}
			v[i][j]=cnt;
		}
	}
	vector<int> anslist;
	for(int i=0; i<m; i++){
		anslist.push_back(ycheck(v,0,i,0));
	}
	for(int i=0; i<n; i++){
		anslist.push_back(xcheck(v,i,0,0));
	}
	sort(anslist.begin(), anslist.end(),cmp);
	int check=anslist[0];
	int xline=-1,yline=-1;
	for(int i=0; i<m; i++){
		if(check==ycheck(v,0,i,0)) yline=i;
	}
	for(int i=0; i<n; i++){
		if(check==xcheck(v,i,0,0)) xline=i;
	}
	int realans=0;
	if(xline>yline){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(xline!=i) realans+=v[i][j];
			}
		}
	}
	else{
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(yline!=j) realans+=v[i][j];
			}
		}
	}
	cout<<realans;
}
int xcheck(vector<vector<int> > &vec,int a,int b,int ans){
	if(m-1==b) return ans+vec[a][b];
	else{
		return xcheck(vec,a,b+1,ans+vec[a][b]);
	}
}
int ycheck(vector<vector<int> > &vec,int a,int b,int ans){
	if(n-1==a) return ans+vec[a][b];
	else{
		return ycheck(vec,a+1,b,ans+vec[a][b]);
	}
}