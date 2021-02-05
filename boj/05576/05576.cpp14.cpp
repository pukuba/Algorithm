#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int a[10],b[10],max1,max2;
	for(int i=0; i<10; i++){
		cin>>a[i];
	}
	for(int j=0; j<10; j++){
		cin>>b[j];
	}
	sort(a,a+10);	
	sort(b,b+10);
	
	max1=a[9]+a[8]+a[7];
	max2=b[9]+b[8]+b[7];
	cout<<max1<<' '<<max2;
}