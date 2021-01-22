#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int N[5],sum=0;
	for(int i=0; i<5; i++){
		cin>>N[i];
		sum+=N[i];
	}
	cout<<sum/5<<'\n';
	sort(N,N+5);
	cout<<N[2];
}