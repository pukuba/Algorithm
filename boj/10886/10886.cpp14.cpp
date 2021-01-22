#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,cute=0,input,nocute=0;
	cin>>T;
	while(T--){
		cin>>input;
		if(input==1){
			cute+=1;
		}
		else if(input==0){
			nocute+=1;
		}
	}
	if(cute>nocute){
		cout<<"Junhee is cute!"<<'\n';
	}
	if(nocute>cute){
		cout<<"Junhee is not cute!"<<'\n';
	}
}