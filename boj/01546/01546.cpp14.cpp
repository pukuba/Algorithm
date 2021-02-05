#include <iostream>

using namespace std;
int main(){
	int T,max=0,a,save;
	float sum;
	cin>>T;
	save=T;
	while(T--){
		cin>>a;
		sum+=a;
		if(max<a)max=a;
	}
	sum/=save;
	printf("%f",sum/max*100);
}