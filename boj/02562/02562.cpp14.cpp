#include <iostream>

using namespace std;
int main(){
	int n[10],max=-999999,num=0;
	for(int i=1; i<10; i++){
		cin>>n[i];
		if(max<n[i]){
			max=n[i];
			num=i;
		}
	}
	cout<<max<<'\n'<<num;
}