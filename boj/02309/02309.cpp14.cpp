#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int n[9],ans=0,h=1;
	for(int i=0; i<9; i++){
		cin>>n[i];
		ans+=n[i];
	}
	ans-=100;
	for(int i=0; i<=7; i++){
		if(h==0){
			break;
		}
		for(int j=i+1; j<=8; j++){
			if(ans==n[i]+n[j]){
				n[i]=-3,n[j]=-3;
				h--;
				break;
			}
		}
	}
	sort(n,n+9);
	for(int i=0; i<=8; i++){
		if(n[i]>0) cout<<n[i]<<'\n';
	}
}