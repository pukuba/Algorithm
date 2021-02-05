#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int input,gap;
	cin>>input; 
	int min=1000000,max=-1000000;
	while(input--){
		cin>>gap;
		if(gap<min){
			min=gap;
		}
		if(max<gap){
			max=gap;
		}
	}
	cout<<min<<' '<<max<<'\n';
}