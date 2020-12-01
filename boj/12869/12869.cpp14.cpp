#include <bits/stdc++.h>

using namespace std;
int d[61][61][61];
int atk(int a,int b,int c){
	if(a<=0) a=0;
	if(b<=0) b=0;
	if(c<=0) c=0;
	if(a==0 && a==b && a==c) return 0;
	int &ret = d[a][b][c];
	if(ret!=-1) return ret;
	return ret=min({atk(a-9,b-3,c-1),atk(a-9,b-1,c-3),atk(a-3,b-9,c-1),atk(a-3,b-1,c-9),atk(a-1,b-3,c-9),atk(a-1,b-9,c-3)
	})+1;
}
int _i[3];
int main(){
	int n;
	cin>>n;
	memset(d,-1,sizeof(d));
	for(int i=0; i<n; i++){
		cin>>_i[i];
	}
	cout<<atk(_i[0],_i[1],_i[2]);
}