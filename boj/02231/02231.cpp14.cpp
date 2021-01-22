#include <iostream>

using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int save=i;
		int ans=i;
		int keep=0;
		while(1){
			if(ans<10){
				keep+=ans;
				break; 
			}
			else{
				keep+=ans%10;
				ans/=10;
			}
		}
		if(keep+i==n){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<"0"<<'\n';
}