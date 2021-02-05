#include <iostream>

using namespace std;
int arr[1696];
int main(){
	int a,b;
	int ans=0;
	int k=1;
	for(int i=1; i<50; i++){
		for(int j=1; j<=i; j++){
			arr[k]=i;
			k++;
		}
	}
	cin>>a>>b;
	for(int i=a; i<=b; i++){
		ans+=arr[i];
	}
	cout<<ans;
}