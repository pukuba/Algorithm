#include <iostream>

using namespace std;
int main(){
	int T,car[5],cnt=0;
	cin>>T;
	for(int i=0; i<5; i++){
		cin>>car[i];
		if(T==car[i]){
			cnt++;
		}
	}
	cout<<cnt<<'\n';	
}