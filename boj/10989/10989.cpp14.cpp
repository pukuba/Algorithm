#include <iostream>

int cnt[10001]{0,};
using namespace std;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int n;
	cin>>n;
	int temp=0;
	for(int i=0; i<n; i++){
		cin>>temp;
		cnt[temp]+=1;
	}
	for(int i=1; i<=10000; i++){
		if(cnt[i]>0){
			for(int j=0; j<cnt[i]; j++){
				cout<<i<<'\n';
			}
		}
	}
}