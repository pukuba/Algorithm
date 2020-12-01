#include <iostream>	

using namespace std;
int main(){
	int num[6],sum=0;
	for(int i=1; i<6; i++){
		cin>>num[i];
		sum+=num[i]*num[i];
	}
	sum%=10;
	cout<<sum<<'\n';
}