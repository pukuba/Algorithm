#include <iostream>
#include <string>

using namespace std;
int main(){
	int arr[8],a=0,b=0;
	for(int i=0; i<8; i++){
		cin>>arr[i];
		if(arr[i]==i+1){
			a++;
		}
		if(arr[i]==8-i){
			b++;
		}
	}
	if(a==8){
		cout<<"ascending"<<'\n';
	}
	else if(b==8){
		cout<<"descending"<<'\n';
	}
	else{
		cout<<"mixed"<<'\n';
	}
}