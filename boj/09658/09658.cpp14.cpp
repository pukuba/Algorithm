#include <iostream>

using namespace std;
int main(){
	int num,arr[1001]={0,0,1,0,1};
	cin>>num;
	for(int i=5; i<=num; i++){
		if(arr[i-1]+arr[i-3]+arr[i-4]==3){
			arr[i]=0;
		}
		else arr[i]=1;
	}
	if(arr[num]==1){
		cout<<"SK"<<'\n';
	}
	else cout<<"CY"<<'\n';
}