#include <iostream>
#include <algorithm>

bool check[10];
using namespace std;
int pos(int c){
	if(c==0){
		if(check[0]){
			return 0;
		} 
		else{
			return 1;
		}
	}
	int len=0;
	while(c>0){
		if(check[c%10]){
			return 0;
		}
		c/=10;
		len++;
	}
	return len;
}
int main(){
	int n,m,ans;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x;
		cin>>x;
		check[x]=true;
	} 
	ans=n-100;
	if(ans<0){
		ans=-ans;
	}
	for(int i=0; i<1000000; i++){
		int c=i;
		int len=pos(c);
		if(len>0){
			int pre=c-n;
			if(pre<0){
				pre=-pre;
			}
			ans=min(ans,len+pre);
		}
	}
	cout<<ans;
}