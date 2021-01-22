#include <bits/stdc++.h>

using namespace std;
int sign[10][10],n,cnt=0;
int ans[10];
string s;
bool check(int index){
	int sum=0;
	for(int i=index; i>=0; i--){
		sum+=ans[i];
		if(sign[i][index]==0) if(sum!=0) return false;
		if(sign[i][index]<0) if(sum>=0) return false;
		if(sign[i][index]>0) if(sum<=0) return false;
	}
	return true;
}
bool go(int index){
	if(index == n ) return true;
	if(sign[index][index]==0){
		ans[index]=0;
		return go(index+1) && check(index);
	} 
	for(int i=1; i<=10; i++){
		ans[index] = sign[index][index]*i;
		if(check(index) && go(index+1)) return true;
	}	
	return false;
}
int main(){
	cin>>n;
	cin>>s;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(s[cnt]=='0') sign[i][j]=0;
			if(s[cnt]=='-') sign[i][j]=-1;
			if(s[cnt]=='+') sign[i][j]=1;
			cnt++;
		}
	}
	go(0);
	for(int i=0; i<n; i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}