#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n,tmp;
	int k[10001]={0,};
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmp;
		k[tmp]++;
	}
	for(int i=1; i<10001;i++){
		if(k[i]!=0){
			for(int j=0; j<k[i];j++){
				cout<<i<<'\n';
			}
		}
	}
}